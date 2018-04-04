/**
 *  @file
 *  @copyright defined in eos/LICENSE.txt
 */
#include <eoslib/eos.hpp>
#include <eoslib/db.hpp>

// @abi action sayhello
// @abi table
struct sayhello {
  /**
  * account to transfer from
  */
  account_name       from;
  /**
  * account to transfer to
  */
  account_name       to;
};