/**
 *  @file
 *  @copyright defined in eos/LICENSE.txt
 */
#include <task.hpp>
#include <task.gen.hpp>

#include <eoslib/db.hpp>
#include <eoslib/types.hpp>
#include <eoslib/raw.hpp>
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
       if( action == N(starttask) ) {
            const auto &kv2 = eosio::current_message<task>();
            eosio::print("Inserting task\n");
            eosio::dump(kv2);
            bytes b = eosio::raw::pack(kv2.info);
            uint32_t err = store_str( N(task), N(task), (char *)kv2.name.get_data(), kv2.name.get_size(), (char*)b.data, b.len);

        } else {
            eosio::print( "Hello World: ", eosio::name(code), "->", eosio::name(action), "\n" );
        }
    }

} // extern "C"
