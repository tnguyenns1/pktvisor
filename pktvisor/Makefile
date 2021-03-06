pktvisor-libs = $(shell pkg-config --libs libnl-3.0) \
                $(shell pkg-config --libs libnl-genl-3.0) \
        	    -lpthread \
		        -lncurses

ifeq ($(CONFIG_LIBPCAP), 1)
pktvisor-libs +=	-lpcap
endif
ifeq ($(CONFIG_GEOIP), 1)
pktvisor-libs +=	-lGeoIP \
			-lz
endif

pktvisor-objs =	dissector.o \
			dissector_eth.o \
			dissector_netlink.o \
			lookup.o \
			proto_arp.o \
			proto_gre.o \
			proto_ethernet.o \
			proto_icmpv4.o \
			proto_icmpv6.o \
			proto_igmp.o \
			proto_ip_authentication_hdr.o \
			proto_ip_esp.o \
			proto_ipv4.o \
			proto_ipv6.o \
			proto_ipv6_dest_opts.o \
			proto_ipv6_fragm.o \
			proto_ipv6_hop_by_hop.o \
			proto_ipv6_in_ipv4.o \
			proto_ipv6_mobility_hdr.o \
			proto_ipv6_no_nxt_hdr.o \
			proto_ipv6_routing.o \
			proto_lldp.o \
			proto_nlmsg.o \
			proto_none.o \
			proto_tcp.o \
			proto_udp.o \
			proto_dns.o \
			pktvisorui.o \
			dnsctxt.o \
			proto_vlan.o \
			proto_vlan_q_in_q.o \
			proto_mpls_unicast.o \
			privs.o \
			proc.o \
			dev.o \
			str.o \
			sig.o \
			sock.o \
			irq.o \
			iosched.o \
			ioops.o \
			link.o \
			xmalloc.o \
			hash.o \
			bpf.o \
			oui.o \
			dns.o \
			pcap_rw.o \
			pcap_sg.o \
			pcap_mm.o \
			ring_rx.o \
			ring_tx.o \
			ring.o \
			tprintf.o \
			timer.o \
			pktvisor.o

ifeq ($(CONFIG_LIBPCAP), 1)
pktvisor-objs +=	bpf_comp.o
endif
ifeq ($(CONFIG_GEOIP), 1)
pktvisor-objs +=	geoip.o
endif
ifeq ($(CONFIG_HWTSTAMP), 1)
pktvisor-objs +=	tstamping.o
endif

pktvisor-eflags = $(shell pkg-config --cflags libnl-3.0) \
		     $(shell pkg-config --cflags libnl-genl-3.0) \
		     -DNEED_TCPDUMP_LIKE_FILTER

pktvisor-confs =	ether.conf \
			tcp.conf \
			udp.conf \
			oui.conf \
			geoip.conf
