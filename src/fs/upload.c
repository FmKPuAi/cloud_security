#include <stdio.h>
#include "nfq_queue.h"
#include "pkt_crypt.h"
#include "pkt_modify.h"

int main(int argc, char **argv)
{
    struct nfq_handle *h = NULL;
    struct nfq_q_handle *qh = NULL;
    
    create_nfq(&h,&qh,0);
    receive_nfq(h);
    unbind_nfq(h,qh);
    return 0;
}
