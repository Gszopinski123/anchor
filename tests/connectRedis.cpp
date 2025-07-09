#include <stdio.h>
#include <stdlib.h>
#include <hiredis/hiredis.h>




int main(void) {
    redisContext * c = redisConnect("127.0.0.1",6379);

    if (c == NULL || c->err) {
        if (c != NULL) {
            printf("Error: %s\n",c->errstr);
        } else {
            printf("can't allocate redis context\n");
        }
        exit(1);
    }
    redisReply *reply = (redisReply*)redisCommand(c, "SET foo bar");
    printf("Reply: %s\n",reply->str);
    freeReplyObject(reply);

    reply = (redisReply*)redisCommand(c, "GET foo");

    printf("Reply: %s\n",reply->str);

    freeReplyObject(reply);

    redisFree(c);

}