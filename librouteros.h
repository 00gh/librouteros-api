/*
    librouteros-api - Connect to RouterOS devices using official API protocol
    Copyright (C) 2012, Håkon Nessjøen <haakon.nessjoen@gmail.com>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

struct ros_result {
	int words;
	char **word;
	char done;
	char re;
	char trap;
	char fatal;
};

int ros_connect(char *address, int port);
int ros_disconnect(int sock);
struct ros_result *ros_send_command(int socket, char *command, ...);
struct ros_result *ros_read_packet(int socket);
void ros_free_result(struct ros_result *result);
char *ros_get(struct ros_result *result, char *key);
int ros_login(int socket, char *username, char *password);

#define ROS_PORT 8728