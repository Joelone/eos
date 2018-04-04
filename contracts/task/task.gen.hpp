#pragma once
#include <eoslib/types.hpp>
#include <eoslib/message.hpp>
#include <eoslib/datastream.hpp>
#include <eoslib/raw_fwd.hpp>

namespace eosio { namespace raw {
   template<typename Stream> inline void pack( Stream& s, const task_info& value ) {
      raw::pack(s, value.desc);
      raw::pack(s, value.bounty);
      raw::pack(s, value.starttime);
      raw::pack(s, value.endtime);
   }
   template<typename Stream> inline void unpack( Stream& s, task_info& value ) {
      raw::unpack(s, value.desc);
      raw::unpack(s, value.bounty);
      raw::unpack(s, value.starttime);
      raw::unpack(s, value.endtime);
   }
   template<typename Stream> inline void pack( Stream& s, const task& value ) {
      raw::pack(s, value.name);
      raw::pack(s, value.info);
   }
   template<typename Stream> inline void unpack( Stream& s, task& value ) {
      raw::unpack(s, value.name);
      raw::unpack(s, value.info);
   }
} }

#include <eoslib/raw.hpp>
namespace eosio {
   void print_ident(int n){while(n-->0){print("  ");}};
   template<typename Type>
   Type current_message_ex() {
      uint32_t size = message_size();
      char* data = (char *)eosio::malloc(size);
      assert(data && read_message(data, size) == size, "error reading message");
      Type value;
      eosio::raw::unpack(data, size, value);
      eosio::free(data);
      return value;
   }
   void dump(const task_info& value, int tab=0) {
      print_ident(tab);print("desc:[");prints_l(value.desc.get_data(), value.desc.get_size());print("]\n");
      print_ident(tab);print("bounty:[");printi(uint64_t(value.bounty));print("]\n");
      print_ident(tab);print("starttime:[");printi(uint64_t(value.starttime));print("]\n");
      print_ident(tab);print("endtime:[");printi(uint64_t(value.endtime));print("]\n");
   }
   template<>
   task_info current_message<task_info>() {
      return current_message_ex<task_info>();
   }
   void dump(const task& value, int tab=0) {
      print_ident(tab);print("name:[");prints_l(value.name.get_data(), value.name.get_size());print("]\n");
      print_ident(tab);print("info:[");print("\n"); eosio::dump(value.info, tab+1);print_ident(tab);print("]\n");
   }
   template<>
   task current_message<task>() {
      return current_message_ex<task>();
   }
} //eosio

