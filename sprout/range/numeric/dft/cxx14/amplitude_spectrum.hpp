/*=============================================================================
  Copyright (c) 2011-2016 Bolero MURAKAMI
  https://github.com/bolero-MURAKAMI/Sprout

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
=============================================================================*/
#ifndef SPROUT_RANGE_NUMERIC_DFT_CXX14_AMPLITUDE_SPECTRUM_HPP
#define SPROUT_RANGE_NUMERIC_DFT_CXX14_AMPLITUDE_SPECTRUM_HPP

#include <sprout/config.hpp>
#include <sprout/container/functions.hpp>
#include <sprout/iterator/type_traits/is_iterator_of.hpp>
#include <sprout/type_traits/enabler_if.hpp>
#include <sprout/numeric/dft/cxx14/amplitude_spectrum.hpp>

namespace sprout {
	namespace range {
		//
		// amplitude_spectrum
		//
		template<
			typename InputRange, typename OutputIterator,
			typename sprout::enabler_if<sprout::is_iterator_outputable<OutputIterator>::value>::type = sprout::enabler
		>
		inline SPROUT_CXX14_CONSTEXPR OutputIterator
		amplitude_spectrum(InputRange const& rng, OutputIterator result) {
			return sprout::amplitude_spectrum(sprout::begin(rng), sprout::end(rng), result);
		}
	}	// namespace range
}	// namespace sprout

#endif	// #ifndef SPROUT_RANGE_NUMERIC_DFT_CXX14_AMPLITUDE_SPECTRUM_HPP