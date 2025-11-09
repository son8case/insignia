#ifndef SON8_INSIGNIA_HXX
#define SON8_INSIGNIA_HXX

namespace son8::insignia {

    template< typename Type >
    struct Creator {
        // default constructor
        auto operator()( ) const -> Type *;
        // copy constructor
        auto operator()( Type const &data ) const -> Type *;
        // default destructor
        auto operator()( Type *data ) const;
    };

    template< typename Type >
    class Pointer {

    };

} // namespace

#endif//SON8_INSIGNIA_HXX
