#include "stdafx.h"
#include "ComponentWithoutTexture.h"
#include "Kernel.h"

namespace scv {

ComponentWithoutTexture::ComponentWithoutTexture(const scv::Point &p1, const scv::Point &p2)
      : ComponentInterface(p1, p2) {
   Kernel::getInstance()->registerComponentWithoutTexture(this);
}

ComponentWithoutTexture::~ComponentWithoutTexture(void) {/*none*/}

void ComponentWithoutTexture::display(void) {
   static Kernel *kernel = Kernel::getInstance();
   static Scissor *scissor = Scissor::getInstance();

   if (_isVisible == false) return;

   Point currPosition = getAbsolutePosition();

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(0, getWidth(), getHeight(), 0);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();

   glViewport(currPosition.x, kernel->getHeight() - (getHeight() + currPosition.y), getWidth(), getHeight());

   scissor->pushScissor(Scissor::ScissorInfo(currPosition.x, kernel->getHeight() - (getHeight() + currPosition.y), getWidth(), getHeight()));
   glPushAttrib(GL_ALL_ATTRIB_BITS);

   glClearColor(1.f, 1.f, 1.f, 1.f);
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   glDisable(GL_TEXTURE_2D);

   render();

   glPopAttrib();

   scissor->popScissor();

   glDisable(GL_DEPTH_TEST);
   glDisable(GL_LIGHTING);
   if (glUseProgram)
      glUseProgram(0);

   kernel->applyDefaultTransformMatrix();
}

} // namespace scv