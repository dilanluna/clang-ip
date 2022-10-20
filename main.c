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

void decm_ip_to_str(uint32_t, char *);

int main() {
  char str_ip[16] = "192.168.1.1";
  uint32_t decm_ip = str_ip_to_decm(str_ip);
  char str_ip2[16];
  decm_ip_to_str(decm_ip, str_ip2);
  printf("%u\n", decm_ip);
  printf("%s\n", str_ip2);

  return 0;
}

uint32_t str_ip_to_decm(char *str_ip) {
  char *token;
  union ip_addr ip;
  int oct = OCTETS;

  memset(&ip, 0, sizeof(union ip_addr));

  token = strtok(str_ip, ".");
  ip.octs[--oct] = atoi(token);

  while (oct > 0) {
    token = strtok(NULL, ".");
    ip.octs[--oct] = atoi(token);
  }

  return ip.decm;
}

void decm_ip_to_str(uint32_t decm_ip, char *str_ip) {
  union ip_addr ip;

  memset(&ip, 0, sizeof(union ip_addr));

  ip.decm = decm_ip;
  sprintf(str_ip, "%u.%u.%u.%u", ip.octs[3], ip.octs[2], ip.octs[1], ip.octs[0]);
}
