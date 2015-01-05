/*
 * Copyright 2015 NSONE, Inc.
 */

#ifndef DNSCTXT_H
#define DNSCTXT_H

#include "uthash.h"

// max length of domain name. 253 is the max according to standard,
// can make it smaller if we truncate and save memory
#define MAX_DNAME_LEN 253

// max LRU table size
// XXX need to make this per table
#define MAX_LRU_SIZE 10000

// max summary table size
#define MAX_SUMMARY_SIZE 10

// accumulator hash table keyed by ip address (in int form)
// or other 32 bit key
struct int32_entry {
    uint32_t key;
    uint64_t count;
    UT_hash_handle hh;
};

// accumulator hash table keyed by string
struct str_entry {
    char key[MAX_DNAME_LEN];
    uint64_t count;
    UT_hash_handle hh;
};

// context structure that gets passed to dns processing function
struct dnsctxt {

    // LRU hash tables

    // source ips
    struct int32_entry *source_table;
    // dest ips
    struct int32_entry *dest_table;
    // malformed (unparsable) query source ips
    struct int32_entry *malformed_table;

    // queried name tables, for 1,2,3 label lengths
    struct str_entry *query_name1_table;
    struct str_entry *query_name2_table;
    struct str_entry *query_name3_table;

    // general packet counters
    uint64_t seen;
    uint64_t incoming;

    // dns header counters
    uint64_t cnt_query;
    uint64_t cnt_reply;
    uint64_t cnt_status_noerror;
    uint64_t cnt_status_srvfail;
    uint64_t cnt_status_nxdomain;
    uint64_t cnt_status_refused;

    // parsed DNS counters
    uint64_t cnt_malformed;
    uint64_t cnt_edns;

};

void dnsctxt_init(struct dnsctxt *ctxt);
void dnsctxt_free(struct dnsctxt *ctxt);
void dnsctxt_table_summary(struct dnsctxt *ctxt);

void dnsctxt_count_ip(struct int32_entry **table, uint32_t key);
void dnsctxt_count_name(struct str_entry **table, char *name);

#endif /* DNSCTXT_H */
