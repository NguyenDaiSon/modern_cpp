// Structured binding: since C++17
// Dai Son, NGUYEN < daisonit@gmail.com >
#include <iostream>
#include <array>

struct mac_header { // i just wrote it for fun with modern C++
	std::array<uint8_t,6> m_dst_mac_addr;
	std::array<uint8_t,6> m_src_mac_addr;
	std::array<uint8_t,2> m_eth_type;
};

int main() {
	mac_header rcv_frame_mac_hdr{ {10,20,30,40,50,60}, {11,21,31,41,51,61},{0x08,0x06} };
	const std::array<uint8_t,6> host_mac_addr{10,20,30,40,50,60};
	const std::array<uint8_t,6> bcast_mac_addr{0xff,0xff,0xff,0xff,0xff};
	const std::array<uint8_t,6> ban_mac_addr{11,21,31,41,51,62}; // should be a list in reality
	const auto& [dst,src,type] = rcv_frame_mac_hdr;
	const auto& [msb,lsb] = type; // network byte order - in the TCP/IP suite to be big-endian
	if ( dst == bcast_mac_addr && msb == 0x08 && lsb == 0x06 ) {
		// Receive ARP broadcast - handle it
	} else if ( dst == host_mac_addr && src != ban_mac_addr ) {
		std::cout << "oh, my dear frame!" << std::endl;
		// if ( msb == 0x08 &&  lsb == 0x00 ) { // below is just demo using tuple access
		if ( std::get<0>(type) == 0x08 && std::get<1>(type) != 0x00) { 
			std::cout << "you encapsulates an ipv4 packet in the payload" << std::endl;
			std::cout << "let me first strip off mac header and ..." << std::endl;
			std::cout << "then i push the ipv4 packet up to Internet Layer" << std::endl;
		}
	}
	return 0;
}
