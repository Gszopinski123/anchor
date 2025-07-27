# anchor
A secure distributed Message/RPC network


### Notes about development
 * so originally I wanted to have my local machine host a rpc server and have the client be in a kubernetes pod easy right? no there were not guides and most guides required you to download more software but I felt that the more third party software I add to this project the more it will bog it down. so I decided that I would do a reverse RPC have the client sit on my machine and have the server send commands to the client