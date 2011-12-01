#ifndef __CODE_GENERATOR_H__
#define __CODE_GENERATOR_H__

#include "ManagedComponent.h"

class CodeGenerator : public Singleton<CodeGenerator> {
friend class Singleton<CodeGenerator>;
public:
   ///////////////////////////////////////////////////////////
   typedef std::list<ManagedComponent *> ManagedList;
   ///////////////////////////////////////////////////////////

   ///////////////////////////////////////////////////////////
   scv::Component *addComponent(const std::string &type);
   void addManagedComponent(scv::Component *object, const std::string &type);

   void deleteComponent(ManagedComponent *managed);   
   ///////////////////////////////////////////////////////////

   ///////////////////////////////////////////////////////////
   bool hasComponent(scv::Component *object) const;
   bool hasComponent(const std::string &name) const;
   ///////////////////////////////////////////////////////////

   ///////////////////////////////////////////////////////////
   ManagedComponent *getManagedComponent(scv::Component *object) const;
   ManagedComponent *getManagedComponent(const std::string &name) const;

   ManagedList getManagedComponents(void) const;
   ///////////////////////////////////////////////////////////

   ///////////////////////////////////////////////////////////
   void generateCode(void);
   ///////////////////////////////////////////////////////////
   
   void setSCVFrame( scv::InternalFrame *frame );

protected:
   ///////////////////////////////////////////////////////////
   CodeGenerator(void);
   virtual ~CodeGenerator(void);
   ///////////////////////////////////////////////////////////

   int getComponentCount(scv::Component::Type type);   

   ManagedList _managed;
   std::map<scv::Component::Type, int> _counter;
   scv::InternalFrame *_scvFrame;
};

#endif //__CODE_GENERATOR_H__