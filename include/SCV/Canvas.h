#ifndef __SCV_CANVAS_H__
#define __SCV_CANVAS_H__

///////////////////////////////////////////////////////////
#include "ComponentWithoutTexture.h"
///////////////////////////////////////////////////////////

namespace scv {

class Canvas : public ComponentWithoutTexture {
public:
   ///////////////////////////////////////////////////////////
   Canvas(const scv::Point &p1, const scv::Point &p2);
   virtual ~Canvas(void);
   ///////////////////////////////////////////////////////////

   ///////////////////////////////////////////////////////////
   virtual void onMouseClick(const scv::MouseEvent &evt);
   virtual void onMouseHold(const scv::MouseEvent &evt);
   virtual void onMouseOver(const scv::MouseEvent &evt);
   virtual void onMouseUp(const scv::MouseEvent &evt);
   virtual void onMouseWheel(const scv::MouseEvent &evt);
   ///////////////////////////////////////////////////////////

   ///////////////////////////////////////////////////////////
   virtual void onKeyPressed(const scv::KeyEvent &evt);
   virtual void onKeyUp(const scv::KeyEvent &evt);
   ///////////////////////////////////////////////////////////

   ///////////////////////////////////////////////////////////
   virtual void onResizing(void);
   virtual void onDragging(void);
   ///////////////////////////////////////////////////////////

   ///////////////////////////////////////////////////////////
   virtual void render(void);
   virtual void update(void);
   ///////////////////////////////////////////////////////////

protected:
private:
};

} // namespace scv


#endif // __SCV_CANVAS_H__