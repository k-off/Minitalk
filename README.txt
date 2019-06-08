MINITALK
A "weekend" project (Rush) at Codam (42).
The project is designed to be completed by a group of two students in 48 hours. 
The goal of the project is to familiarize the students with signals, signal handling and accompanying issues, such as signal loss.

Basic objectives:
- create two programs, client and server, to send a text
  message using user-defined signals only;
- handle errors, such as wrong user input;
- use no more than 8 signals per character;
- data transmission speed more than 100 characters per second;

Above the basics, current version supports:
- data transmission speed ~2000 characters per second;
- 'ping-pong' - server answers after each signal is received;
- retransmission of the lost signals;
- server waits for the next client after the message was received and printed;

What is NOT supported:
- simultaneous data transmission from multiple clients;
- data compression;

How to use:
- download
- in terminal run following:
/project_path/make
./project_path/server
- in a second terminal window run:
./project_path/client <server_process_id> <message>
