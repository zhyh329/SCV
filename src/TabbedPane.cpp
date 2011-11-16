#include "stdafx.h"
#include "TabbedPane.h"
#include "StaticLabel.h"

#include "Kernel.h"

namespace scv {

const int TabbedPane::s_tabSpacing  = 10;
const int TabbedPane::s_barHeight   = 22;

TabbedPane::TabbedPane(const scv::Point &p1, const scv::Point &p2) : ComponentWithTexture(p1, p2) {
   _currecOverTab = _currSelectedTab = -1;
   _index.push_back(s_tabSpacing);
   _type = TABBEDPANE;

   createTexture();
}

void TabbedPane::onMouseClick(const scv::MouseEvent &evt) {
}
void TabbedPane::onMouseHold(const scv::MouseEvent &evt) {
}
void TabbedPane::onMouseOver(const scv::MouseEvent &evt) {
}
void TabbedPane::onMouseUp(const scv::MouseEvent &evt) {
}
void TabbedPane::onMouseWheel(const scv::MouseEvent &evt) {
}

void TabbedPane::onKeyPressed(const scv::KeyEvent &evt) {
}
void TabbedPane::onKeyUp(const scv::KeyEvent &evt) {
}

void TabbedPane::onSizeChange(void) {
}
void TabbedPane::onPositionChange(void) {
}

void TabbedPane::addChild(Component *object) {
   addChild(object, "none", false);
}

void TabbedPane::addChild(Component *object, const std::string &label, bool resize) {
   ComponentWithTexture::addChild(object);

   if (_currSelectedTab == -1) _currSelectedTab = 0;

   if (resize) {
      object->setWidth(getWidth());
      object->setHeight(getHeight() - s_barHeight);
   }   
   object->setRelativePosition(Point(0, s_barHeight));

   _index.push_back(_index.back() + (s_tabSpacing * 2) + FontTahoma::getInstance()->getStringLength(label));
   _labels.push_back(label);
   _resize.push_back(resize);
}

void TabbedPane::removeChild(Component *object) {
   if (hasChild(object)) {
      int index = 0;
      Component::List::iterator iter = _children.begin();
      while((*iter) != object) {
         ++iter;
         ++index;
      }
      _index.erase(_index.begin() + index);
      _labels.erase(_labels.begin() + index);
      _resize.erase(_resize.begin() + index);
   }
   ComponentWithTexture::removeChild(object);
}

void TabbedPane::processMouse(const scv::MouseEvent &evt) {
   static Kernel *kernel = Kernel::getInstance();

   if (isDragging() || isResizing()) {
      Component::processMouse(evt);
      if (_currSelectedTab != -1 && isResizing()) {
         setCurrPanel();
      }
   } else {

      if (_currSelectedTab == -1 || !_receivingCallbacks) {
         Component::processMouse(evt);
         return;
      } else if(_currSelectedTab != -1) {
         getChild(_currSelectedTab)->setDraggable(false);
         getChild(_currSelectedTab)->processMouse(evt);
      }

      Component::processMouse(evt);

      Point currPosition = getAbsolutePosition();
      Point relativeMouse = evt.getPosition();

      if (evt.getState() == MouseEvent::UP) setCurrPanel();

      // open menu
      if (isInside(evt.getPosition())) {
         _currecOverTab = -1;
         if (kernel->requestMouseUse(this)) {
            // over menu
            for (int i = 0; i < _children.size(); i++) {
               if (relativeMouse.x > _index[i] + currPosition.x && relativeMouse.x < _index[i + 1] + currPosition.x - 1
                  && relativeMouse.y > currPosition.y && relativeMouse.y < currPosition.y + s_barHeight) {
                     if (_currSelectedTab != i) _currecOverTab = i;
                     break;
               }
            }
            if (isFocused()) {
               if (evt.getState() == MouseEvent::CLICK && evt.getButton() == MouseEvent::LEFT) {
                  for (int i = 0; i < _children.size(); i++) {
                     if (relativeMouse.x > _index[i] + currPosition.x && relativeMouse.x < _index[i + 1] + currPosition.x - 1
                        && relativeMouse.y > currPosition.y && relativeMouse.y < currPosition.y + s_barHeight) {
                           _currSelectedTab = i;
                           _currecOverTab   = -1;
                           setCurrPanel();
                           break;
                     }
                  }
               }
            }
         }
      } else {
         _currecOverTab = -1;
      }
   }
}

void TabbedPane::processKey(const scv::KeyEvent &evt) {
   static Kernel *kernel = Kernel::getInstance();

   if (_currSelectedTab == -1) return;
   if(!_receivingCallbacks) return;

   if (isFocused() && evt.getState() == KeyEvent::DOWN) {
      Point currPosition = getAbsolutePosition();

      if (evt.getKeyString() == "Left") {
         _currecOverTab = -1;
         if (_currSelectedTab == 0) {
            _currSelectedTab = _children.size() - 1;
            setCurrPanel();
         } else {
            _currSelectedTab--;
            setCurrPanel();
         }

      } else if (evt.getKeyString() == "Right") {
         _currecOverTab = -1;
         _currSelectedTab = (_currSelectedTab + 1) % _children.size();
         setCurrPanel();
      }

   } else if (_currSelectedTab != -1) {
      getChild(_currSelectedTab)->processKey(evt);
   }
}

void TabbedPane::display(void) {
   static Kernel *kernel = Kernel::getInstance();
   static Scissor *scissor = Scissor::getInstance();
   static FontTahoma *font = FontTahoma::getInstance();
   static ColorScheme *scheme = ColorScheme::getInstance();

   if (_cTexture == NULL || _isVisible == false) return;

   if (_currSelectedTab != -1) {
      setCurrPanel();
      getChild(_currSelectedTab)->display();
   }

   Point currPosition = getAbsolutePosition();
 
   scissor->pushScissor(getScissor());

   _cTexture->enable();

   // background
   scheme->applyColor(ColorScheme::MENUBAR);
   _cTexture->display(currPosition.x, currPosition.y, 0, getWidth(), s_barHeight);

   glColor3f(0.f,0.f,0.f);
   // vertical
   _cTexture->display(currPosition.x, currPosition.y + s_barHeight, 4, 1, getHeight() - s_barHeight);
   _cTexture->display(currPosition.x + getWidth() - 1, currPosition.y + s_barHeight, 4, 1, getHeight() - s_barHeight);

   // horizontal
   _cTexture->display(currPosition.x, currPosition.y + getHeight() - 1, 4, getWidth(), 1);

   // line bottom
   _cTexture->display(currPosition.x, currPosition.y + s_barHeight, 4, getWidth(), 1);

   if (_currSelectedTab != -1) {
      int size = _index[_currSelectedTab + 1] - _index[_currSelectedTab];

      scheme->applyColor(ColorScheme::PANEL);
      _cTexture->display(currPosition.x + _index[_currSelectedTab] + 1, currPosition.y + 2, 4, size - 2, 1);
      _cTexture->display(currPosition.x + _index[_currSelectedTab] + 0, currPosition.y + 3, 4, size, s_barHeight - 2);

      glColor3f(0.f,0.f,0.f);
      _cTexture->display(currPosition.x + _index[_currSelectedTab] + 2, currPosition.y + 1, 4, size - 4, 1);

      _cTexture->display(currPosition.x + _index[_currSelectedTab] + 1, currPosition.y + 2, 4, 1, 1);
      _cTexture->display(currPosition.x + _index[_currSelectedTab+1] - 2, currPosition.y + 2, 4, 1, 1);

      _cTexture->display(currPosition.x + _index[_currSelectedTab], currPosition.y + 3, 4, 1, s_barHeight-3);
      _cTexture->display(currPosition.x + _index[_currSelectedTab+1] - 1, currPosition.y + 3, 4, 1, s_barHeight-3);

      scheme->applyDefaultModulate();
   }

   if (_currecOverTab != -1) {

      int size = _index[_currecOverTab + 1] - _index[_currecOverTab];

      scheme->applyColor(ColorScheme::OVERCOMPONENTS);

      //vertical
      _cTexture->display(currPosition.x + _index[_currecOverTab] + size - 2, currPosition.y + 3, 2, 1, s_barHeight - 6);
      _cTexture->display(currPosition.x + _index[_currecOverTab] + 1       , currPosition.y + 3, 2, 1, s_barHeight - 6);
      //horizontal
      _cTexture->display(currPosition.x + _index[_currecOverTab] + 3       , currPosition.y  +1             , 2, size - 6, 1);
      _cTexture->display(currPosition.x + _index[_currecOverTab] + 3       , currPosition.y + s_barHeight -2, 2, size - 6, 1);

      // pixel border
      _cTexture->display(currPosition.x + _index[_currecOverTab] + 1       , currPosition.y + 1              , 3,  2,  2);
      _cTexture->display(currPosition.x + _index[_currecOverTab] + 1       , currPosition.y + s_barHeight - 1, 3,  2, -2);
      _cTexture->display(currPosition.x + _index[_currecOverTab] + size - 1, currPosition.y + 1              , 3, -2,  2);
      _cTexture->display(currPosition.x + _index[_currecOverTab] + size - 1, currPosition.y + s_barHeight - 1, 3, -2, -2);

      // center select
      _cTexture->display(currPosition.x + _index[_currecOverTab] + 3, currPosition.y + 3, 1, size - 6, s_barHeight - 6);

      scheme->applyDefaultModulate();
   }
   _cTexture->disable();

   for (int i = 0; i < _labels.size(); i++) {
      if (i == _currSelectedTab) {
         StaticLabel::display(currPosition.x + s_tabSpacing + _index[i], currPosition.y + 4, _labels[i], scheme->getColor(ColorScheme::CONTEXTMENUFONT));
      } else {
         StaticLabel::display(currPosition.x + s_tabSpacing + _index[i], currPosition.y + 4, _labels[i]);
      }
   }

   scissor->popScissor();

}

void TabbedPane::createTexture(void) {
   Kernel *kernel = Kernel::getInstance();
   if ((_cTexture = kernel->getWidgetTexture(Kernel::TABBEDPANE)) != NULL) return;

   // create texture object
   _cTexture = new ComponentTexture(8, 16);
   kernel->setWidgetTexture(Kernel::TABBEDPANE, _cTexture);

   _cTexture->setTextureEnvMode(GL_MODULATE);

   // background
   MatrixTemplate<ColorRGBA> middle(1, 1, ColorRGBA(200,200,200,255));
   _cTexture->addTexture(Point(0,0), middle); // 0

   // over
   MatrixTemplate<ColorRGBA> overCenter(1,1, ColorRGBA(240,240,240,50));
   _cTexture->addTexture(Point(1,0), overCenter); // 1

   MatrixTemplate<ColorRGBA> overBorder(1,1, ColorRGBA(210,210,210,150));
   _cTexture->addTexture(Point(0,1), overBorder); // 2

   MatrixTemplate<ColorRGBA> pixelBorder(2,2, ColorRGBA(220,220,220,100));
   Texture2D::drawPoint(pixelBorder, Point(0, 0),ColorRGBA(0,0,0,0));
   _cTexture->addTexture(Point(2,0), pixelBorder); // 3

   // selected
   MatrixTemplate<ColorRGBA> selected(1,1, ColorRGBA(255,255,255,255));
   _cTexture->addTexture(Point(4,0), selected); // 4

   _cTexture->createTexture();
}

void TabbedPane::setCurrPanel(void) {
   if (_currSelectedTab == -1) return;
   if (_resize[_currSelectedTab]) {
      getChild(_currSelectedTab)->setWidth(getWidth());
      getChild(_currSelectedTab)->setHeight(getHeight() - s_barHeight);
   }
   getChild(_currSelectedTab)->setRelativePosition(Point(0, s_barHeight));
}

} // namespace scv
