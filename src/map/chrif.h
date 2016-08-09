// Copyright (c) Athena Dev Teams - Licensed under GNU GPL
// For more information, see LICENCE in the main folder

#ifndef _CHRIF_H_
#define _CHRIF_H_

#include "../common/cbasetypes.h"
#include <time.h>

enum sd_state { ST_LOGIN, ST_LOGOUT, ST_MAPCHANGE };
struct auth_node {
	uint32 account_id, char_id;
	int login_id1, login_id2, sex, fd;
	time_t expiration_time; // # of seconds 1/1/1970 (timestamp): Validity limit of the account (0 = unlimited)
	struct map_session_data *sd;	//Data from logged on char.
	struct mmo_charstatus *char_dat;	//Data from char server.
	unsigned int node_created; //timestamp for node timeouts
	enum sd_state state; //To track whether player was login in/out or changing maps.
};

/// Char-server (to login-server) operation request
enum chrif_req_op {
	// Request to login-server
	CHRIF_OP_LOGIN_BLOCK = 1,
	CHRIF_OP_LOGIN_BAN,
	CHRIF_OP_LOGIN_UNBLOCK,
	CHRIF_OP_LOGIN_UNBAN,
	CHRIF_OP_LOGIN_CHANGESEX,
	CHRIF_OP_LOGIN_VIP,

	// Char-server operation
	CHRIF_OP_BAN,
	CHRIF_OP_UNBAN,
};

void chrif_setuserid(char* id);
void chrif_setpasswd(char* pwd);
void chrif_checkdefaultlogin(void);
int chrif_setip(const char* ip);
void chrif_setport(uint16 port);

int chrif_isconnected(void);
void chrif_check_shutdown(void);

extern int chrif_connected;
extern int other_mapserver_count;

struct auth_node* chrif_search(uint32 account_id);
struct auth_node* chrif_auth_check(uint32 account_id, uint32 char_id, enum sd_state state);
bool chrif_auth_delete(uint32 account_id, uint32 char_id, enum sd_state state);
bool chrif_auth_finished(struct map_session_data* sd);

void chrif_authreq(struct map_session_data* sd, bool autotrade);
void chrif_authok(int fd);
int chrif_scdata_request(uint32 account_id, uint32 char_id);
int chrif_skillcooldown_request(uint32 account_id, uint32 char_id);
int chrif_skillcooldown_save(struct map_session_data *sd);
int chrif_skillcooldown_load(int fd);

int chrif_save(struct map_session_data* sd, int flag);
int chrif_charselectreq(struct map_session_data* sd, uint32 s_ip);
int chrif_changemapserver(struct map_session_data* sd, uint32 ip, uint16 port);

int chrif_searchcharid(uint32 char_id);
int chrif_changeemail(int id, const char *actual_email, const char *new_email);
int chrif_req_login_operation(int aid, const char* character_name, unsigned short operation_type, int timediff, int val1, int val2);
int chrif_updatefamelist(struct map_session_data *sd);
int chrif_buildfamelist(void);
int chrif_save_scdata(struct map_session_data *sd);
int chrif_ragsrvinfo(int base_rate,int job_rate, int drop_rate);
int chrif_char_offline(struct map_session_data *sd);
int chrif_char_offline_nsd(uint32 account_id, uint32 char_id);
int chrif_char_reset_offline(void);
int send_users_tochar(void);
int chrif_char_online(struct map_session_data *sd);
int chrif_changesex(struct map_session_data *sd);
int chrif_chardisconnect(struct map_session_data *sd);
int chrif_divorce(int partner_id1, int partner_id2);

int chrif_removefriend(uint32 char_id, int friend_id);
int chrif_send_report(char* buf, int len);

void chrif_parse_ack_vipActive(int fd);

int chrif_req_charban(int aid, const char* character_name, int timediff);
int chrif_req_charunban(int aid, const char* character_name);

int chrif_bsdata_request(uint32 char_id);
int chrif_bsdata_save(struct map_session_data *sd, bool quit);

void do_final_chrif(void);
void do_init_chrif(void);

int chrif_flush_fifo(void);

#endif /* _CHRIF_H_ */
