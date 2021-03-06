/*****************************************************************************
* This file is part of Kvazaar HEVC encoder.
*
* Copyright (C) 2013-2015 Tampere University of Technology and others (see
* COPYING file).
*
* Kvazaar is free software: you can redistribute it and/or modify it under
* the terms of the GNU Lesser General Public License as published by the
* Free Software Foundation; either version 2.1 of the License, or (at your
* option) any later version.
*
* Kvazaar is distributed in the hope that it will be useful, but WITHOUT ANY
* WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
* FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for
* more details.
*
* You should have received a copy of the GNU General Public License along
* with Kvazaar.  If not, see <http://www.gnu.org/licenses/>.
****************************************************************************/

/*
* \file
*/

#include "strategies/avx2/resample-avx2.h"

#if COMPILE_INTEL_AVX2
#include "strategyselector.h"

#include "scaler/scaler-avx2.h"
#endif

int kvz_strategy_register_resample_avx2(void * opaque)
{
  bool success = true;
#if COMPILE_INTEL_AVX2
  success &= kvz_strategyselector_register(opaque, "resample_block_step", "avx2_3", 42, kvz_alt2_block_step_resample_func_avx2);
  success &= kvz_strategyselector_register(opaque, "resample_block_step", "avx2_2", 43, kvz_alt1_block_step_resample_func_avx2);
  success &= kvz_strategyselector_register(opaque, "resample_block_step", "avx2", 40, kvz_default_block_step_resample_func_avx2);

  success &= kvz_strategyselector_register(opaque, "opaque_resample_block_step", "avx2", 44, kvz_opaque_block_step_resample_func_avx2);
  
  success &= kvz_strategyselector_register(opaque, "resample", "avx2", 41, kvz_alt_resample_func_avx2);
  success &= kvz_strategyselector_register(opaque, "resample", "avx2", 40, kvz_default_resample_func_avx2);
#endif
  return success;
}
