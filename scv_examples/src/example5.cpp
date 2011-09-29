/* Button Group
 * 
 */

#include <SCV/Kernel.h>
#include <SCV/ColorScheme.h>
#include <SCV/ProgressBar.h>
#include <SCV/Slider.h>
#include <SCV/ButtonGroup.h>
#include <SCV/RadioButton.h>


namespace {



class MyRadioButton : public scv::RadioButton {
public:
   MyRadioButton(scv::Point p1 , std::string name) : scv::RadioButton(p1, false, name) {
      //Adicionar o componente ao kernel
      scv::Kernel::getInstance()->addComponent(this);
   }

private:

};

}

void example5_main() {
	scv::Kernel* kernel = scv::Kernel::getInstance();
	scv::ColorScheme* scheme = scv::ColorScheme::getInstance();

	scheme->loadScheme(scv::ColorScheme::clean);
	kernel->setWindowSize(500, 500);

   scv::ButtonGroup * bgroup = new scv::ButtonGroup();
   
   MyRadioButton * b1 = new MyRadioButton(scv::Point(20,20),"Botao 1");
   MyRadioButton * b2 = new MyRadioButton(scv::Point(20,20+30),"Botao 2");
   MyRadioButton * b3 = new MyRadioButton(scv::Point(20,20+30*2),"Botao 3");
   MyRadioButton * b4 = new MyRadioButton(scv::Point(20,20+30*3),"Botao 4");

  b1->registerButtonGroup(bgroup);
  b2->registerButtonGroup(bgroup);
  b3->registerButtonGroup(bgroup);
  b4->registerButtonGroup(bgroup);

	kernel->setFramesPerSecond(60);
	kernel->run();
}