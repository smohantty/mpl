//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include "find_if.hpp"
#include "../functional/identity.hpp"
#include "../types/bool.hpp"
#include "../utility/always.hpp"

namespace kvasir {
	namespace mpl {
		/// \brief resolves to false_ if any element in the input pack fulfills the provided
		/// predicate, otherwise true_. \requires Type `F` shall be a `continuation predicate` and
		/// C shall be any `continuation`. example call<any<same_as<void>>,void,int,char> resolves
		/// to true_.
		template <typename F = identity, typename C = identity>
		using none = find_if<F, always<bool_<false>, C>, always<bool_<true>, C>>;
		namespace eager {
			template <typename List, template <typename...> class Cond = identity>
			using none = call<unpack<mpl::none<cfe<Cond>>>, List>;
		}
	} // namespace mpl
} // namespace kvasir
