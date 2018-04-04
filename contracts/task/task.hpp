/**
 *  @file
 *  @copyright defined in eos/LICENSE.txt
 */
#include <eoslib/eos.hpp>
#include <eoslib/db.hpp>
#include <eoslib/string.hpp>

	struct task_info {
		eosio::string desc;
		uint64_t bounty;
		uint64_t starttime;
		uint64_t endtime;
	};
	// @abi action starttask
	// @abi table
	struct task {
		eosio::string name;
		task_info	info;
	};
