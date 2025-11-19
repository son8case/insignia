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
        void operator()( Type *data ) const noexcept;
    };

    template< typename Type >
    class Pointer {
        using Data_ = Type *;
        Data_ data_;
    public:
        using Copy = Pointer const &;
        using Move = Pointer &&;
        using Create = Creator< Type >;
        using Delete = Creator< Type >;
        // constructors
        Pointer( ) : data_{ Create{}( ) } { }
       ~Pointer( ) noexcept { Delete{}( data_ ); }
        Pointer( Copy copy ) : data_{ Create{}( *copy.data_ ) } { }
        Pointer( Move move ) noexcept : data_{ move.data_ } { move.data_ = nullptr; }
        void operator=( Copy copy ) {
            auto temp = copy;
            auto t = temp.data_;
            temp.data_ = data_;
            data_ = t;
        }
        void operator=( Move move ) noexcept {
            Delete{}( data_ );
            data_ = move.data_;
            move.data_ = nullptr;
        }
        // pointer accessors
        auto operator->( ) const noexcept -> Type * { return data_; }
        auto operator*( ) const noexcept -> Type & { return *data_; }
    };

} // namespace

#endif//SON8_INSIGNIA_HXX
