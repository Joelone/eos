/**
 *  @file
 *  @copyright defined in eos/LICENSE.txt
 */
#include <hello.hpp>

/**
 *  The init() and apply() methods must have C calling convention so that the blockchain can lookup and
 *  call these methods.
 */
extern "C" {

    /**
     *  This method is called once when the contract is published or updated.
     */
    void init()  {
       eosio::print( "Init World!\n" );
    }

    /// The apply method implements the dispatch of events to this contract
    void apply( uint64_t code, uint64_t action ) {
        if( action == N(sayhello) ){
            eosio::print( "Hello World: ", eosio::name(code)," ", eosio::name(action), " to ", eosio::name(eosio::current_message< sayhello >().to), "\n" );
            // HELLO_WORLD::apply_sayhello( eosio::current_message< sayhello >() );
        } else {
            eosio::print( "Hello World: ", eosio::name(code), "->", eosio::name(action), "\n" );
        }
    }

} // extern "C"
