/*  This file is part of the Vc library. {{{
Copyright © 2009-2015 Matthias Kretz <kretz@kde.org>

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the names of contributing organizations nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

}}}*/

#include "../scalar/types.h"

#ifndef VC_SSE_TYPES_H_
#define VC_SSE_TYPES_H_

#ifdef Vc_DEFAULT_IMPL_SSE
#define Vc_DOUBLE_V_SIZE 2
#define Vc_FLOAT_V_SIZE 4
#define Vc_INT_V_SIZE 4
#define Vc_UINT_V_SIZE 4
#define Vc_SHORT_V_SIZE 8
#define Vc_USHORT_V_SIZE 8
#endif

namespace Vc_VERSIONED_NAMESPACE
{
namespace SSE
{
template <typename T> using Vector = Vc::Vector<T, VectorAbi::Sse>;
typedef Vector<double>         double_v;
typedef Vector<float>           float_v;
typedef Vector<int>               int_v;
typedef Vector<unsigned int>     uint_v;
typedef Vector<short>           short_v;
typedef Vector<unsigned short> ushort_v;
typedef Vector<char>            schar_v;
typedef Vector<unsigned char>   uchar_v;

template <typename T> using Mask = Vc::Mask<T, VectorAbi::Sse>;
typedef Mask<double>         double_m;
typedef Mask<float>           float_m;
typedef Mask<int>               int_m;
typedef Mask<unsigned int>     uint_m;
typedef Mask<short>           short_m;
typedef Mask<unsigned short> ushort_m;
typedef Mask<char>            schar_m;
typedef Mask<unsigned char>   uchar_m;


template <typename T> struct Const;

template <typename T> struct is_vector : public std::false_type {};
template <typename T> struct is_vector<Vector<T>> : public std::true_type {};
template <typename T> struct is_mask : public std::false_type {};
template <typename T> struct is_mask<Mask<T>> : public std::true_type {};
}  // namespace SSE

namespace Traits
{
template <class T> struct
is_simd_vector_internal<Vector<T, VectorAbi::Sse>>
  : public is_valid_vector_argument<T> {};

template<typename T> struct is_simd_mask_internal<Mask<T, VectorAbi::Sse>>
  : public std::true_type {};
}  // namespace Traits
}  // namespace Vc

#endif // VC_SSE_TYPES_H_
