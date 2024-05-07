#include <stdio.h>
#include "include/ip.h"

int main() {
  strip_t str_net;
  strip_t str_brdcst;
  strip_t str_host = "192.168.1.1";
  strip_t str_mask = "255.255.255.0";
 
  printf("IP Address: %s\n", str_host);
  printf("Network Mask: %s\n", str_mask);

  ip_t host_ip = str_to_ip(str_host);
  ip_t mask_ip = str_to_ip(str_mask);
  ip_t net_ip = get_net_ip(host_ip, mask_ip);
  ip_t brdcst_ip = get_brdcst_ip(host_ip, mask_ip);
  
  ip_to_str(net_ip, str_net);
  ip_to_str(brdcst_ip, str_brdcst);

  printf("Network IP: %s\n", str_net);
  printf("Broadcast IP: %s\n", str_brdcst);

  return 0;
}

