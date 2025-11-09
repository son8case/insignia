#ifndef SON8_IMPL_INSIGNIA_HXX
#define SON8_IMPL_INSIGNIA_HXX

#include <son8/insignia.hxx>

namespace son8::insignia {

    template< typename Type >
    auto Creator< Type >::operator()( ) const -> Type * { return new Type; }

    template< typename Type >
    auto Creator< Type >::operator()( Type const &data ) const -> Type * { return new Type{ data }; }

    template< typename Type >
    auto Creator< Type >::operator()( Type *data ) const { delete data; }

}

#endif//SON8_IMPL_INSIGNIA_HXX
