#include "manager.h"
#include "managerUI.h"
#include "test.h"

int Amtui::wc = 0;
bool Amtui::initialised = false;

void Amtui::init() {
	if (!initialised) {
		//cout << "initialising ..." << endl;
		initscr();
		initialised = true;
	}
	wc++;
}
void Amtui::run() {
	display(Home);
}
Amtui::Amtui() {
	init();
}
Amtui::~Amtui() {
	//cout << "destroying window.." << wc << endl;
	if (--wc == 0) {
		endwin();
		cout << "all windows destroyed!" << endl;
	}
}

void Amtui::displayEmail() {
	mvprintw(tab[id(ebx)].my, fieldindent, "User email");

	WINDOW* ebox = newwin(tbx.my, tbx.mx, tab[id(ebx)].Y(), tab[id(ebx)].X());
	refresh();
	box(ebox, 0, 0);
	wrefresh(ebox);
}
void Amtui::displayPassword() {
	mvprintw(tab[id(pbx)].my, fieldindent, "User Password");

	WINDOW* pbox = newwin(tbx.my, tbx.mx, tab[id(pbx)].Y(), tab[id(pbx)].X());
	refresh();
	box(pbox, 0, 0);
	wrefresh(pbox);
}
void Amtui::displayPassword2() {
	mvprintw(tab[id(vbx)].my, fieldindent, "Verify Password");

	WINDOW* vbox = newwin(tbx.my, tbx.mx, tab[id(vbx)].Y(), tab[id(vbx)].X());
	refresh();
	box(vbox, 0, 0);
	wrefresh(vbox);
}

void Amtui::displayOkCancel() {
	WINDOW* obox = newwin(ocb.my, ocb.mx, tab[id(obx)].Y(), tab[id(obx)].X());
	refresh();
	box(obox, 0, 0);
	mvwprintw(obox, 1, 1, "   Ok");
	wrefresh(obox);

	WINDOW* cbox = newwin(ocb.my, ocb.mx, tab[id(cbx)].Y(), tab[id(cbx)].X());
	refresh();
	box(cbox, 0, 0);
	mvwprintw(cbox, 1, 1, " Cancel");
	wrefresh(cbox);
}
void Amtui::cycletab() {
	int i = tabc % fc < 0 ? tabc % fc + fc : tabc % fc;
	if (!(i < fc && i >= 0)) throw AssertErr();
	move(tab[i].my, tab[i].mx);
	tabc++;
}

void Amtui::cycleback() { //?: conditional (if)
	int i = --tabc % fc < 0 ? tabc % fc + fc : tabc % fc;
	if (!(i < fc && i >= 0)) throw AssertErr();
	move(tab[i].my, tab[i].mx);
}
void Amtui::configure(Point2D t1[], tab_cycler t2[], int size) {
	idx.clear(), tab.clear();
	session.user.clear();
	session.getStatus().errors.clear();
	for (int i = 0; i < size; i++) {
		tab.push_back(t1[i]);
		idx.push_back(t2[i]);
	}
	fc = size;
}
int Amtui::id(tab_cycler t) {//tab-cycler==int
	for (int i = 0; i < idx.size(); i++) {
		if (idx[i] == t)return i;
	}return -1;
}
void Amtui::displayLogin() {
	session.setStatus(LoginSession);
	Point2D tmp[] = { t[ebx],t[pbx],t[obx],t[cbx]};
	tab_cycler t2[] = { ebx,pbx,obx,cbx };
	configure(tmp, t2, (sizeof(t2) / sizeof(t2[0])));
	drawBorder();
	move(1, 1);
	printw("LOGIN WINDOW!");
	displayEmail();
	displayPassword();
	displayOkCancel();
	eventLoop();
}
void Amtui::displayReg() {
	session.setStatus(RegisterSession);
	Point2D tmp[] = { t[ebx],t[pbx],t[vbx],t[obx],t[cbx]};
	tab_cycler t2[] = { ebx,pbx,vbx,obx,cbx };
	configure(tmp, t2, (sizeof(t2) / sizeof(t2[0])));
	drawBorder();
	move(1, 1);
	printw("REGISTER WINDOW!");
	displayEmail();
	displayPassword();
	displayPassword2();
	displayOkCancel();
	eventLoop();
}
void Amtui::display(Screen s) {
	switch (s)
	{
	case Login:
		displayLogin();
		break;
	case Home:
		displayHome();
		break;
	case Reg:
		displayReg();
		break;
	case Reset:
		break;
	case Sess:
		displaySession();
		break;
	default:
		break;
	}
}
void Amtui::display() {
	switch (session.getStatusCode())
	{
	case UserSession:
		display(Sess);
		break;
	case LoginErrorSession:
		uitext(win, sln, session.toString());
		break;
	default:
		break;
	}
}
void Amtui::okHandle() {
	switch (session.getStatusCode())
	{
	case LoginSession:
		Manager::Login();
		break;
	case RegisterSession:
		Manager::Register();
		break;
	default:
		break;
	}
	display();
}
void Amtui::uitext(WINDOW* w, Point2D l, string text) {
	mvwprintw(w, l.my, l.mx, text.c_str());
	wrefresh(w);
	refresh();
}
void Amtui::drawBorder() {
	clear();
	win = newwin(wsz.my, wsz.mx, 0,0);
	refresh();
	box(win, 0, 0);
	wrefresh(win);
}
void Amtui::banner() {
	mvwprintw(win, 1, 2, " ___        _    _     __ __                               ");
	mvwprintw(win, 2, 2, "| . | _ _ _| |_ | |_  |  \\  \\ ___ ._ _  ___  ___  ___  _ _ ");
	mvwprintw(win, 3, 2, "|   || | | | |  | . | |     |<_> || ' |<_> |/ . |/ ._>| '_>");
	mvwprintw(win, 4, 2, "|_|_|`___| |_|  |_|_| |_|_|_|<___||_|_|<___|\\_. |\\___.|_|  ");
	mvwprintw(win, 5, 2, "                                            <___'          ");
	wrefresh(win);
}
void Amtui::displaySession() {
	drawBorder();
	//Fireworks f(win);
	//f.explode();
	//display(Home);
	getch();
}
void Amtui::displayHome() {
	drawBorder();
	banner();
	//create window for input
	string choices[] = { "Login","Register","Reset Password","Exit" };
	int mc = sizeof(choices) / sizeof(choices[0]);
	WINDOW* menuwin = newwin(mc + 2, wsz.mx - (12), wsz.my - 8, mc);
	box(menuwin, 0, 0);
	refresh();
	wrefresh(menuwin);
	//use arrow keys
	keypad(menuwin, TRUE);
	enum  scr { login, reg, reset, ex };
	int choice;
	int highlight = 0;
	cbreak();
	while (1) {
		for (int i = 0; i < mc; i++) {
			if (i == highlight)
				wattron(menuwin, A_REVERSE);
			mvwprintw(menuwin, i + 1, 1, choices[i].c_str());
			wattroff(menuwin, A_REVERSE);
		}
		choice = wgetch(menuwin);
		//printw(" \n %d",choice);
		switch (choice) {
		case 9:
		case 60418:
			highlight++;
			if (highlight == mc)
				highlight = 0;
			break;
		case 60511:
		case 60419:
			highlight--;
			if (highlight == -1)
				highlight = mc - 1;
			break;
		default:
			break;
		}if (choice == 10 || choice == ' ')break;
	}
	switch (highlight)
	{
	case login:
		display(Login);
		break;
	case reg:
		display(Reg);
		break;
	case reset:
		display(Reset);
		break;
	default:
		exit(0);
		break;
	}
}

void Amtui::eventLoop() {
	keypad(stdscr, TRUE);
	halfdelay(5);
	noecho();
	cycletab();
	while (char c = getch()) {//tab=9
		if (c == ERR)continue;
		int ctab = (tabc % fc == 0) ? fc - 1 : (tabc % fc < 0 ? tabc % fc + (fc - 1) : tabc % fc - 1);
		assert(ctab >= 0 && ctab < fc);
		// printw("%d ",c);
		switch (c) {
		case ' ':
		case 10:
		case -53:
			if (c == ' ') {
				if (ctab == id(obx)) {
					okHandle();
					break;
				}
				if (ctab == id(cbx)) {
					displayHome();
				}
				if (ctab == id(ebx)) {
					printw("%c", c);
					session.user.Email.append(1, c);
				}
				if (ctab == id(pbx) || ctab == id(vbx)) {
					printw("*");
					session.user.Password.append(1, c);
				}
				break;
			}
			if (ctab == id(obx)) {
				okHandle();
				break;
			}
			if (ctab == id(cbx)) {
				displayHome();
			}break;
		case 9:
		case 2:
			cycletab();
			break;
		case '_':
		case 3:
			cycleback();
			break;
		default:
			if (ctab == id(ebx)) {
				if (int(c) != 127)printw("%c", c);
				session.user.Email.append(1, c);
			}
			if (ctab == id(pbx) || ctab == id(vbx)) {
				if (int(c) != 127)printw("*");
				session.user.Password.append(1, c);
			}
			break;
		}
	}
}