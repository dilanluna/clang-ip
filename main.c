#include <errno.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define OCTETS 4

union ip_addr {
  uint8_t octs[OCTETS];
  uint32_t decm;
};

uint32_t str_ip_to_decm(char *);

int main() {
  char str_ip[16] = "192.168.1.1";
  uint32_t decm_ip = str_ip_to_decm(str_ip);
  printf("%u\n", decm_ip);

  return 0;
}

uint32_t str_ip_to_decm(char *str_ip) {
  int oct;
  char *token;
  union ip_addr ip;

  memset(&ip, 0, sizeof(union ip_addr));

  token = strtok(str_ip, ".");
  ip.octs[0] = atoi(token);

  for (oct = 1; oct <= OCTETS; oct++) {
    token = strtok(NULL, ".");
    ip.octs[oct] = atoi(token);
  }

  return ntohl(ip.decm);
}
