#ifndef CPP_VARIANT_H
#define CPP_VARIANT_H

namespace cpp
{

struct Variant
{
   enum Type
   {
      typeNull = 0,
      typeInt,
      typeDouble,
      typeBool,
      typePointer,
      typeString,
      typeObject,
      typeObjC,
   };

   Type type;
   union
   {
      int valInt;
      double valDouble;
      bool valBool;
      struct
      {
         unsigned int valStringLen;
         const char *valStringPtr;
      };
      hx::Object *valObject;
      void *valPointer;
      #if defined(__OBJC__) && defined(HXCPP_OBJC)
      id  valObjC;
      #endif
   };

   inline Variant() : type(typeNull), valPointer(0) { }
   inline Variant(const null &) : type(typeNull), valPointer(0) { }
   inline Variant(bool inValue) : type(typeBool), valBool(inValue) { }
   inline Variant(int inValue) : type(typeInt), valInt(inValue) { }
   inline Variant(double inValue) : type(typeDouble), valDouble(inValue) { }
   inline Variant(::String inValue) : type(typeString), valStringPtr(inValue.__s), valStringLen(inValue.length) { }
   #if defined(__OBJC__) && defined(HXCPP_OBJC)
   inline Variant(const id inValue) : type(typeObjC), valObjC(inValue) { }
   #endif

   inline Variant(Dynamic &inRHS) : type(typeObject), valObject(inRHS.mPtr) { }
   inline Variant(hx::Object *inValue) : type(typeObject), valObject(inValue) { }
   inline Variant(void *inValue) : type(typePointer), valPointer(inValue) { }

   inline operator Dynamic ()
   {
      switch(type)
      {
         case typeNull: return null();
         case typeInt: return valInt;
         case typeDouble: return valDouble;
         case typeBool: return valBool;
         case typeString: return String(valStringPtr, valStringLen);
         case typeObject: return valObject;
         case typePointer: return null(); // todo
         case typeObjC: return null(); // todo
      }
      return null();
   }


   inline operator String()
   {
      switch(type)
      {
         case typeNull: return String();
         case typeInt: return String(valInt);
         case typeDouble: return String(valDouble);
         case typeBool: return String(valBool);
         case typeString: return String(valStringPtr, valStringLen);
         case typeObject: return Dynamic(valObject);
         case typePointer: return String(); // todo
         case typeObjC: return String(); // todo
      }
      return String();
   }


   inline void mark(hx::MarkContext *__inCtx)
   {
      if (type==typeString)
      {
         HX_MARK_STRING(valStringPtr);
      }
      else if (type==typeObject)
      {
         HX_MARK_OBJECT(valObject);
      }
   }
   #ifdef HXCPP_VISIT_ALLOCS
   void visit(hx::VisitContext *__inCtx)
   {
      if (type==typeString)
      {
         HX_VISIT_STRING(valStringPtr);
      }
      else if (type==typeObject)
      {
         HX_VISIT_OBJECT(valObject);
      }
   }
   #endif

};


} // end namespace cpp

#endif
