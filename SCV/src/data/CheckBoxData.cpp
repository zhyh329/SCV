#include "data.h"

namespace scv {
namespace data {

const unsigned char CheckBox[] = {
   0x8e,0x8f,0x8f,0xff,0x8e,0x8f,0x8f,0xff,0x8e,0x8f,0x8f,0xff,
   0x8e,0x8f,0x8f,0xff,0x8e,0x8f,0x8f,0xff,0x8e,0x8f,0x8f,0xff,
   0x8e,0x8f,0x8f,0xff,0x8e,0x8f,0x8f,0xff,0x8e,0x8f,0x8f,0xff,
   0x8e,0x8f,0x8f,0xff,0x8e,0x8f,0x8f,0xff,0x8e,0x8f,0x8f,0xff,
   0x8e,0x8f,0x8f,0xff,0x8e,0x8f,0x8f,0xff,0xf4,0xf4,0xf4,0xff,
   0xf4,0xf4,0xf4,0xff,0xf4,0xf4,0xf4,0xff,0xf4,0xf4,0xf4,0xff,
   0xf4,0xf4,0xf4,0xff,0xf4,0xf4,0xf4,0xff,0xf4,0xf4,0xf4,0xff,
   0xf4,0xf4,0xf4,0xff,0xf4,0xf4,0xf4,0xff,0xf4,0xf4,0xf4,0xff,
   0xf4,0xf4,0xf4,0xff,0x8e,0x8f,0x8f,0xff,0x8e,0x8f,0x8f,0xff,
   0xf4,0xf4,0xf4,0xff,0xae,0xb3,0xb9,0xff,0xae,0xb3,0xb9,0xff,
   0xae,0xb3,0xb9,0xff,0xae,0xb3,0xb9,0xff,0xae,0xb3,0xb9,0xff,
   0xae,0xb3,0xb9,0xff,0xaf,0xb4,0xba,0xff,0xb4,0xb9,0xbd,0xff,
   0xbb,0xbe,0xc1,0xff,0xf4,0xf4,0xf4,0xff,0x8e,0x8f,0x8f,0xff,
   0x8e,0x8f,0x8f,0xff,0xf4,0xf4,0xf4,0xff,0xae,0xb3,0xb9,0xff,
   0xcb,0xcf,0xd5,0xff,0xcb,0xcf,0xd5,0xff,0xcb,0xcf,0xd5,0xff,
   0xcb,0xcf,0xd5,0xff,0xd0,0xd3,0xd8,0xff,0xd5,0xd8,0xdc,0xff,
   0xdb,0xdd,0xdf,0xff,0xc1,0xc3,0xc5,0xff,0xf4,0xf4,0xf4,0xff,
   0x8e,0x8f,0x8f,0xff,0x8e,0x8f,0x8f,0xff,0xf4,0xf4,0xf4,0xff,
   0xae,0xb3,0xb9,0xff,0xcb,0xcf,0xd5,0xff,0xcb,0xcf,0xd5,0xff,
   0xcd,0xd1,0xd6,0xff,0xd2,0xd5,0xda,0xff,0xd8,0xdb,0xde,0xff,
   0xdd,0xdf,0xe1,0xff,0xe2,0xe3,0xe4,0xff,0xc6,0xc7,0xc8,0xff,
   0xf4,0xf4,0xf4,0xff,0x8e,0x8f,0x8f,0xff,0x8e,0x8f,0x8f,0xff,
   0xf4,0xf4,0xf4,0xff,0xae,0xb3,0xb9,0xff,0xcd,0xd1,0xd7,0xff,
   0xd0,0xd4,0xd9,0xff,0xd4,0xd7,0xdb,0xff,0xdb,0xdd,0xdf,0xff,
   0xe1,0xe2,0xe3,0xff,0xe5,0xe6,0xe6,0xff,0xe8,0xe8,0xe8,0xff,
   0xcc,0xcd,0xcd,0xff,0xf4,0xf4,0xf4,0xff,0x8e,0x8f,0x8f,0xff,
   0x8e,0x8f,0x8f,0xff,0xf4,0xf4,0xf4,0xff,0xb2,0xb7,0xbc,0xff,
   0xd5,0xd8,0xdc,0xff,0xda,0xdc,0xdf,0xff,0xe0,0xe1,0xe3,0xff,
   0xe8,0xe8,0xe8,0xff,0xec,0xec,0xec,0xff,0xed,0xed,0xed,0xff,
   0xed,0xed,0xed,0xff,0xd4,0xd5,0xd6,0xff,0xf4,0xf4,0xf4,0xff,
   0x8e,0x8f,0x8f,0xff,0x8e,0x8f,0x8f,0xff,0xf4,0xf4,0xf4,0xff,
   0xb8,0xbb,0xbf,0xff,0xdd,0xdf,0xe1,0xff,0xe4,0xe5,0xe5,0xff,
   0xea,0xea,0xea,0xff,0xef,0xef,0xef,0xff,0xf2,0xf2,0xf2,0xff,
   0xf2,0xf2,0xf2,0xff,0xf2,0xf2,0xf2,0xff,0xdc,0xdd,0xde,0xff,
   0xf4,0xf4,0xf4,0xff,0x8e,0x8f,0x8f,0xff,0x8e,0x8f,0x8f,0xff,
   0xf4,0xf4,0xf4,0xff,0xbc,0xbf,0xc2,0xff,0xe3,0xe4,0xe5,0xff,
   0xe9,0xe9,0xe9,0xff,0xed,0xed,0xed,0xff,0xf2,0xf2,0xf2,0xff,
   0xf4,0xf4,0xf4,0xff,0xf5,0xf5,0xf5,0xff,0xf4,0xf4,0xf4,0xff,
   0xe1,0xe2,0xe2,0xff,0xf4,0xf4,0xf4,0xff,0x8e,0x8f,0x8f,0xff,
   0x8e,0x8f,0x8f,0xff,0xf4,0xf4,0xf4,0xff,0xc2,0xc4,0xc6,0xff,
   0xe9,0xe9,0xe9,0xff,0xed,0xed,0xed,0xff,0xf0,0xf0,0xf0,0xff,
   0xf4,0xf4,0xf4,0xff,0xf6,0xf6,0xf6,0xff,0xf6,0xf6,0xf6,0xff,
   0xf6,0xf6,0xf6,0xff,0xe6,0xe6,0xe6,0xff,0xf4,0xf4,0xf4,0xff,
   0x8e,0x8f,0x8f,0xff,0x8e,0x8f,0x8f,0xff,0xf4,0xf4,0xf4,0xff,
   0xca,0xcb,0xcc,0xff,0xd4,0xd4,0xd5,0xff,0xdb,0xdb,0xdc,0xff,
   0xe0,0xe1,0xe1,0xff,0xe6,0xe7,0xe7,0xff,0xea,0xeb,0xeb,0xff,
   0xeb,0xec,0xec,0xff,0xeb,0xeb,0xec,0xff,0xe9,0xe9,0xea,0xff,
   0xf4,0xf4,0xf4,0xff,0x8e,0x8f,0x8f,0xff,0x8e,0x8f,0x8f,0xff,
   0xf4,0xf4,0xf4,0xff,0xf4,0xf4,0xf4,0xff,0xf4,0xf4,0xf4,0xff,
   0xf4,0xf4,0xf4,0xff,0xf4,0xf4,0xf4,0xff,0xf4,0xf4,0xf4,0xff,
   0xf4,0xf4,0xf4,0xff,0xf4,0xf4,0xf4,0xff,0xf4,0xf4,0xf4,0xff,
   0xf4,0xf4,0xf4,0xff,0xf4,0xf4,0xf4,0xff,0x8e,0x8f,0x8f,0xff,
   0x8e,0x8f,0x8f,0xff,0x8e,0x8f,0x8f,0xff,0x8e,0x8f,0x8f,0xff,
   0x8e,0x8f,0x8f,0xff,0x8e,0x8f,0x8f,0xff,0x8e,0x8f,0x8f,0xff,
   0x8e,0x8f,0x8f,0xff,0x8e,0x8f,0x8f,0xff,0x8e,0x8f,0x8f,0xff,
   0x8e,0x8f,0x8f,0xff,0x8e,0x8f,0x8f,0xff,0x8e,0x8f,0x8f,0xff,
   0x8e,0x8f,0x8f,0xff
};

const unsigned char CheckBoxPressed[] = {
   0x8e,0x8f,0x8f,0xff,0x8e,0x8f,0x8f,0xff,0x8e,0x8f,0x8f,0xff,
   0x8e,0x8f,0x8f,0xff,0x8e,0x8f,0x8f,0xff,0x8e,0x8f,0x8f,0xff,
   0x8e,0x8f,0x8f,0xff,0x8e,0x8f,0x8f,0xff,0x8e,0x8f,0x8f,0xff,
   0x8e,0x8f,0x8f,0xff,0x8e,0x8f,0x8f,0xff,0x8e,0x8f,0x8f,0xff,
   0x8e,0x8f,0x8f,0xff,0x8e,0x8f,0x8f,0xff,0xf4,0xf4,0xf4,0xff,
   0xf4,0xf4,0xf4,0xff,0xf4,0xf4,0xf4,0xff,0xf4,0xf4,0xf4,0xff,
   0xf4,0xf4,0xf4,0xff,0xf4,0xf4,0xf4,0xff,0xf4,0xf4,0xf4,0xff,
   0xf8,0xf8,0xf8,0xff,0xf9,0xf9,0xf9,0xff,0xf6,0xf6,0xf6,0xff,
   0xf4,0xf4,0xf4,0xff,0x8e,0x8f,0x8f,0xff,0x8e,0x8f,0x8f,0xff,
   0xf4,0xf4,0xf4,0xff,0xae,0xb3,0xb9,0xff,0xae,0xb3,0xb9,0xff,
   0xae,0xb3,0xb9,0xff,0xae,0xb3,0xb9,0xff,0xae,0xb3,0xb9,0xff,
   0xc9,0xcc,0xd0,0xff,0x9d,0xa7,0xc0,0xff,0x77,0x86,0xab,0xff,
   0xdc,0xdf,0xe4,0xff,0xf5,0xf5,0xf5,0xff,0x8e,0x8f,0x8f,0xff,
   0x8e,0x8f,0x8f,0xff,0xf4,0xf4,0xf4,0xff,0xae,0xb3,0xb9,0xff,
   0xcb,0xcf,0xd5,0xff,0xcb,0xcf,0xd5,0xff,0xcb,0xcf,0xd5,0xff,
   0xcc,0xd0,0xd6,0xff,0xed,0xee,0xf1,0xff,0x57,0x6a,0x9d,0xff,
   0x44,0x5a,0x92,0xff,0xb9,0xbf,0xd0,0xff,0xf6,0xf6,0xf6,0xff,
   0x8e,0x8f,0x8f,0xff,0x8e,0x8f,0x8f,0xff,0xf4,0xf4,0xf4,0xff,
   0xae,0xb3,0xb9,0xff,0xcb,0xcf,0xd5,0xff,0xcb,0xcf,0xd5,0xff,
   0xcd,0xd1,0xd6,0xff,0xe0,0xe2,0xe6,0xff,0xaf,0xb8,0xcf,0xff,
   0x45,0x5a,0x92,0xff,0x65,0x77,0xa5,0xff,0xe7,0xe7,0xe8,0xff,
   0xf4,0xf4,0xf4,0xff,0x8e,0x8f,0x8f,0xff,0x8e,0x8f,0x8f,0xff,
   0xf4,0xf4,0xf4,0xff,0xae,0xb3,0xb9,0xff,0xd5,0xd9,0xdd,0xff,
   0xdf,0xe2,0xe5,0xff,0xd5,0xd8,0xdc,0xff,0xf2,0xf3,0xf4,0xff,
   0x5e,0x71,0xa1,0xff,0x47,0x5c,0x94,0xff,0xbc,0xc3,0xd6,0xff,
   0xdb,0xdc,0xdc,0xff,0xf4,0xf4,0xf4,0xff,0x8e,0x8f,0x8f,0xff,
   0x8e,0x8f,0x8f,0xff,0xf4,0xf4,0xf4,0xff,0xc5,0xc9,0xcd,0xff,
   0xc9,0xcf,0xdd,0xff,0xa3,0xae,0xc8,0xff,0xed,0xee,0xee,0xff,
   0xba,0xc1,0xd5,0xff,0x49,0x5e,0x96,0xff,0x64,0x76,0xa5,0xff,
   0xf8,0xf8,0xf8,0xff,0xd5,0xd5,0xd6,0xff,0xf4,0xf4,0xf4,0xff,
   0x8e,0x8f,0x8f,0xff,0x8e,0x8f,0x8f,0xff,0xf4,0xf4,0xf4,0xff,
   0xde,0xe0,0xe1,0xff,0x6e,0x7f,0xaa,0xff,0x47,0x5c,0x94,0xff,
   0xcf,0xd4,0xe2,0xff,0x67,0x78,0xa7,0xff,0x4b,0x60,0x97,0xff,
   0xb7,0xbf,0xd5,0xff,0xf6,0xf6,0xf6,0xff,0xdc,0xdd,0xde,0xff,
   0xf4,0xf4,0xf4,0xff,0x8e,0x8f,0x8f,0xff,0x8e,0x8f,0x8f,0xff,
   0xf4,0xf4,0xf4,0xff,0xcd,0xcf,0xd1,0xff,0xde,0xe1,0xe9,0xff,
   0x48,0x5d,0x95,0xff,0x49,0x5f,0x96,0xff,0x4b,0x60,0x97,0xff,
   0x61,0x73,0xa4,0xff,0xf8,0xf9,0xfa,0xff,0xf4,0xf4,0xf4,0xff,
   0xe1,0xe2,0xe2,0xff,0xf4,0xf4,0xf4,0xff,0x8e,0x8f,0x8f,0xff,
   0x8e,0x8f,0x8f,0xff,0xf4,0xf4,0xf4,0xff,0xc6,0xc8,0xca,0xff,
   0xea,0xec,0xf0,0xff,0x8b,0x99,0xbb,0xff,0x4a,0x5f,0x97,0xff,
   0x4c,0x61,0x98,0xff,0xb0,0xb9,0xd1,0xff,0xf9,0xf9,0xf9,0xff,
   0xf6,0xf6,0xf6,0xff,0xe6,0xe6,0xe6,0xff,0xf4,0xf4,0xf4,0xff,
   0x8e,0x8f,0x8f,0xff,0x8e,0x8f,0x8f,0xff,0xf4,0xf4,0xf4,0xff,
   0xca,0xcb,0xcc,0xff,0xda,0xda,0xdb,0xff,0xdf,0xe2,0xe9,0xff,
   0x8c,0x99,0xba,0xff,0x90,0x9d,0xbd,0xff,0xf2,0xf3,0xf6,0xff,
   0xec,0xed,0xed,0xff,0xeb,0xeb,0xec,0xff,0xe9,0xe9,0xea,0xff,
   0xf4,0xf4,0xf4,0xff,0x8e,0x8f,0x8f,0xff,0x8e,0x8f,0x8f,0xff,
   0xf4,0xf4,0xf4,0xff,0xf4,0xf4,0xf4,0xff,0xf4,0xf4,0xf4,0xff,
   0xf5,0xf5,0xf5,0xff,0xf9,0xf9,0xf9,0xff,0xf8,0xf8,0xf8,0xff,
   0xf5,0xf5,0xf5,0xff,0xf4,0xf4,0xf4,0xff,0xf4,0xf4,0xf4,0xff,
   0xf4,0xf4,0xf4,0xff,0xf4,0xf4,0xf4,0xff,0x8e,0x8f,0x8f,0xff,
   0x8e,0x8f,0x8f,0xff,0x8e,0x8f,0x8f,0xff,0x8e,0x8f,0x8f,0xff,
   0x8e,0x8f,0x8f,0xff,0x8e,0x8f,0x8f,0xff,0x8e,0x8f,0x8f,0xff,
   0x8e,0x8f,0x8f,0xff,0x8e,0x8f,0x8f,0xff,0x8e,0x8f,0x8f,0xff,
   0x8e,0x8f,0x8f,0xff,0x8e,0x8f,0x8f,0xff,0x8e,0x8f,0x8f,0xff,
   0x8e,0x8f,0x8f,0xff
};

} // namespace data
} // namespace scv
