/*=============================================================================
  Copyright (c) 2011-2014 Bolero MURAKAMI
  https://github.com/bolero-MURAKAMI/Sprout

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
=============================================================================*/
#ifndef SPROUT_ARRAY_MAKE_ARRAY_HPP
#define SPROUT_ARRAY_MAKE_ARRAY_HPP

#include <cstddef>
#include <type_traits>
#include <sprout/config.hpp>
#include <sprout/index_tuple/metafunction.hpp>
#include <sprout/array/array.hpp>
#include <sprout/utility/forward.hpp>
#include <sprout/type_traits/common_decay.hpp>

namespace sprout {
	//
	// make_array
	//
	template<typename T, typename... Types>
	inline SPROUT_CONSTEXPR sprout::array<typename std::remove_cv<T>::type, sizeof...(Types)>
	make_array(Types&&... args) {
		return sprout::array<typename std::remove_cv<T>::type, sizeof...(Types)>{{T(SPROUT_FORWARD(Types, args))...}};
	}
	// !!! OLD:
//	template<typename... Types>
//	inline SPROUT_CONSTEXPR sprout::array<typename sprout::common_decay<Types...>::type, sizeof...(Types)>
//	make_array(Types&&... args) {
//		typedef sprout::array<
//			typename sprout::common_decay<Types...>::type,
//			sizeof...(Types)
//		> type;
//		return type{{typename sprout::common_decay<Types...>::type(SPROUT_FORWARD(Types, args))...}};
//	}

	//
	// make_common_array
	//
	template<typename... Types>
	inline SPROUT_CONSTEXPR sprout::array<typename sprout::common_decay<Types...>::type, sizeof...(Types)>
	make_common_array(Types&&... args) {
		typedef sprout::array<
			typename sprout::common_decay<Types...>::type,
			sizeof...(Types)
		> type;
		return type{{typename sprout::common_decay<Types...>::type(SPROUT_FORWARD(Types, args))...}};
	}

	//
	// convert_array
	//	[[deprecated]]
	//
	template<typename T, typename Converter, typename... Types>
	SPROUT_DEPRECATED
	inline SPROUT_CONSTEXPR sprout::array<T, sizeof...(Types)>
	convert_array(Converter&& conv, Types&&... args) {
		return sprout::make_array<T>(SPROUT_FORWARD(Converter, conv)(SPROUT_FORWARD(Types, args))...);
	}
}	// namespace sprout

#endif	// #ifndef SPROUT_ARRAY_MAKE_ARRAY_HPP
