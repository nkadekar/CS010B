#ifndef __BBOARD_H__
#define __BBOARD_H__

#include <string>
#include <vector>
#include "Message.h"
#include "User.h"
#include "Topic.h"
#include "Reply.h"

using namespace std;

class BBoard {

 private:
   string title;
	vector<User> user_list;
	const User * current_user;
	vector<Message *> message_list;

 public:
	BBoard();
	BBoard(const string &);
	~BBoard();
	bool loadUsers(const string &);
 	bool loadMessages(const string &);
 	bool saveMessages(const string &);
 	void login();
 	void run();

 private:
    void addTopic();
    void addReply();
    const User * getUser(const string &, const string &) const;     void displayMenu() const;
    void display() const;
    void parseChildren(vector<int> &, vector<string> &);
};

#endif