#ifndef CPP_INT64_INCLUDED
#define CPP_INT64_INCLUDED

namespace cpp
{

class Int64Handler
{
   public:
      static inline const char *getName() { return "cpp.Int64"; }
      static inline String toString( const void *inData ) { return String( *(Int64 *)inData ); }
      static inline void handler(DynamicHandlerOp op, const void *inData, void *outResult)
      {
         if (op==dhoToString)
            *(String *)outResult = toString(inData);
         else if (op==dhoGetClassName)
            *(const char **)outResult = getName();
      }
};

typedef Struct<Int64,Int64Handler> Int64Struct;


}

inline cpp::Int64Struct _hx_int64_make(int a, int b) { return (((cpp::Int64)(unsigned int)a)<<32) | (unsigned int)b; }
inline bool _hx_int64_is_neg(cpp::Int64 a) { return a<0; }
inline bool _hx_int64_is_zero(cpp::Int64 a) { return a==0; }
inline bool _hx_int64_eq(cpp::Int64 a, cpp::Int64 b) { return a==b; }
inline bool _hx_int64_neq(cpp::Int64 a, cpp::Int64 b) { return a!=b; }
inline int _hx_int64_compare(cpp::Int64 a, cpp::Int64 b)
{
   return a==b ? 0 : a<b ? -1 : 1;
}
inline int _hx_int64_ucompare(cpp::Int64 a, cpp::Int64 b)
{
   return a==b ? 0 : ( ::cpp::UInt64)a<( ::cpp::UInt64)b ? -1 : 1;
}
inline String _hx_int64_to_string(cpp::Int64Struct a) { return a; }

inline cpp::Int64Struct _hx_int64_neg(cpp::Int64 a) { return -a; }
inline cpp::Int64Struct _hx_int64_complement(cpp::Int64 a) { return ~a; }

inline cpp::Int64Struct _hx_int64_pre_increment(cpp::Int64Struct &ioVal) {
   return ++ioVal.get();
}
inline cpp::Int64Struct _hx_int64_post_increment(cpp::Int64Struct &ioVal) {
   return ioVal.get()++;
}
inline cpp::Int64Struct _hx_int64_pre_decrement(cpp::Int64Struct &ioVal) {
   return --ioVal.get();
}
inline cpp::Int64Struct _hx_int64_post_decrement(cpp::Int64Struct &ioVal) {
   return ioVal.get()--;
}

inline cpp::Int64Struct _hx_int64_sub(cpp::Int64 a, cpp::Int64 b) { return a-b; }
inline cpp::Int64Struct _hx_int64_add(cpp::Int64 a, cpp::Int64 b) { return a+b; }
inline cpp::Int64Struct _hx_int64_mul(cpp::Int64 a, cpp::Int64 b) { return a*b; }
inline cpp::Int64Struct _hx_int64_div(cpp::Int64 a, cpp::Int64 b) { return a/b; }
inline cpp::Int64Struct _hx_int64_mod(cpp::Int64 a, cpp::Int64 b) { return a%b; }
inline cpp::Int64Struct _hx_int64_and(cpp::Int64 a, cpp::Int64 b) { return a&b; }
inline cpp::Int64Struct _hx_int64_or(cpp::Int64 a, cpp::Int64 b) { return a|b; }
inline cpp::Int64Struct _hx_int64_xor(cpp::Int64 a, cpp::Int64 b) { return a^b; }
inline cpp::Int64Struct _hx_int64_shl(cpp::Int64 a, int b) { return a<<(b&63); }
inline cpp::Int64Struct _hx_int64_shr(cpp::Int64 a, int b) { return a>>(b&63); }
inline cpp::Int64Struct _hx_int64_ushr(cpp::Int64 a, int b) { return ((cpp::UInt64)a)>>(b&63); }
inline int _hx_int64_high(cpp::Int64Struct a) { return (int)( a.get() >>32 ); }
inline int _hx_int64_low(cpp::Int64Struct a) { return (int)( a.get()  & 0xffffffff ); }



#endif
