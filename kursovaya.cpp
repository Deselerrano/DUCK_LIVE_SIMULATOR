#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "windows.h"

using namespace std;

//глобальные переменные, которые помогут нам рандоно задать уткам те или иные параметры(вектор нужен для того чтобы у всех уток были разные имена)
int random = 92;
vector<string> names = { "Тьюринг", "Ульжор", "Вриглей", "Иосиф", "Брэнсон", "Цэйдор", "Декстер", "Маин", "Лайн", "БлэкБарт", "Михаель", "Марсианин",
"Эльма", "Твиксик", "Хорня", "БлэкДжек", "МарчелоМастрояни", "Клепсидра", "Тигги", "Тасман", "Фрис", "Табби", "Норберт", "Дикий", "Соло", "Рауза", "Жорж",
"ДымДымыч", "Оливера", "Брецель", "Элиза", "Цингун", "Кренделек", "Брейгель", "Сиджи", "Лорд", "Ганс", "Нитто", "МяуСайрус", "Кошмарик", "Фестер", "Саске",
"Виви", "Гофман", "Вуаль", "Гарнерри", "Бастьян", "Гайем", "Бурбон", "Гравюра", "Вивьен", "Адье", "Влад", "Гастон", "Виктория", "Вивьен", "Бернар", "Адье",
"Готье", "Бонд", "Бусидо", "Бансэй", "Дариск", "Акико", "Банзай", "Аяме", "Дариск", "Акару", "Банзай", "Атари", "Чиз", "Лала", "Оладушек", "Ли-Ли", "Педро",
"Мертен", "Дашка", "Пеле", "Геральд", "Сидзи", "Чародей", "Юджен", "Михасик", "Каору", "Чеппи", "Сильва", "Паунта", "Пеле", "Биггс", "Ферч", "Уэйф", "Дегай" };
string kluvs[8] = { "Пямой", "Плоский", "Удлиненный", "Курпный", "Узкий", "Короткий", "Широкий", "Пологий" };
string colors[12] = { "Красный", "Синий", "Голубой", "Серый", "Коричневый", "Зелёный", "Салатовый", "Пурпурный", "Фиолетовый", "Розовый", "Жёлтый", "Оранжевый" };
string tails[10] = { "Прямой", "С косицами", "Выемчатый", "С вырезкой", "Лировтдный", "Закруглённый", "Стуменчатый", "Широкий", "Крышевидный", "Клиновидный" };
string bludos[10] = { "раки", "моллюски", "червяки", "личинки комаров", "горох", "пшеница", "ячмень", "рожь", "бобы", "творог" };
string wings[5] = { "Удлинённые", "Широкие", "Эллептические", "Узкие", "Маленькие" };

//функция, помогающая выдать рандомное имя каждой утке
string random_name() {
	int a = rand() % random;
	string bckp;
	bckp = names[a];
	names.erase(names.begin() + a);
	random -= 1;
	return bckp;
}
void nachalo() {
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "| Добро пожаловать в игру Большая охота! |" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	Sleep(1000);
	system("cls");
}
void menu(int day) {
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "| Выберите возможное действие (для выбора действия введите его номер, затем нажмите Enter) |" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << " Прошло " << day << " дней Большой охоты, осталось ещё " << 9 - day;
	cout << endl;
	cout << " 1 - Посмотреть информацию по конкретной утке на определенном озере/ферме" << endl;
	cout << " 2 - Получить общую информаццию по конкретному озеру" << endl;
	cout << " 0 - Начать день охоты (" << day + 1 << "ый)" << endl;
}

//описание абстрактного класса предка для уток
class MamaCryak {
protected:
	string name;
	bool know_home;
	string home;
	int weight;
	MamaCryak* next;
	int fly;
	int swim;
	int migration;
public:
	friend class Ozero;
	friend class Hunter;
	friend void migration(Ozero* a, Ozero* b, Ozero* c);
	MamaCryak() : name(random_name()), know_home(0), home("-"), weight((rand() % 4) + 2), next(NULL), fly(0), migration(0), swim(0) {};
	string is_name() { return name; };
	void migration_end() {
		migration = 2;
	}
	void migration_again() {
		migration = 1;
	}
	void off_fly() {
		fly = 0;
	}
	void pre_off_fly() {
		fly = 2;
	}
	virtual ~MamaCryak() {};
	virtual void get_info() = 0;
	virtual int is_know() = 0;
	virtual int is_fly() = 0;
	virtual int is_swim() = 0;
	virtual int is_hide() = 0;
	virtual int is_chill() = 0;
	virtual int is_migration() = 0;
};
//описания класа потомков с особенностями каждой утки(с виртуальеыми функциями)
class Shirokonozhka : public MamaCryak {
	string kluv;
	int health;
public:
	Shirokonozhka() : kluv(kluvs[rand() % 8]), health(rand() % 101) {
		know_home = 1;
		swim = 1;
	};
	virtual ~Shirokonozhka() {};
	virtual int is_fly() {
		return 0;
	}
	virtual int is_swim() {
		if ((this->swim == 1) || (this->swim == 2)) {
			return 1;
		}
		else {
			return 0;
		}
	}
	virtual int is_hide() {
		return 0;
	}
	virtual int is_chill() {
		return 0;
	}
	virtual int is_migration() {
		return 0;
	}
	virtual int is_know() {
		return 1;
	}
	virtual  void get_info() {
		cout << "Здравствуйте, мой вид Широконожка меня зовут " << name << "." << endl;
		cout << "Я вешу целых " << weight << " кило! " << endl;
		if (swim == 1) {
			cout << "Более того, я умею плавать." << endl;
		}
		else if (swim == 2) {
			cout << "Умение плавать помогло мне однажды сбежать с фермы." << endl;
		}
		else {
			cout << "Жаль, что я не умею плавать." << endl;
		}
		cout << "Кстати, мой клюв " << kluv << ", вам он нравится?" << endl;
		cout << "А еще я здоров(а) на все " << health << "%" << endl;
		cout << "Проживаю я на " << home << endl;
		cout << "Пока пока, мне пора!" << endl;
		cout << endl;
	}
};
class Krohali : public MamaCryak {
	bool hide;
	string color_eye;
	string color_wings;

public:
	Krohali() : hide(1), color_eye(colors[rand() % 12]), color_wings(colors[rand() % 12]) {};
	virtual ~Krohali() {};
	virtual int is_fly() {
		return 0;
	}
	virtual int is_swim() {
		return 0;
	}
	virtual int is_hide() {
		return 1;
	}
	virtual int is_chill() {
		return 0;
	}
	virtual int is_migration() {
		return 0;
	}
	virtual int is_know() {
		return 0;
	}
	virtual  void get_info() {
		cout << "Добрый вечер, я уточка вида Крохали, у меня есть прелестное имя " << name << "." << endl;
		cout << "Вешу я немного, в районе " << weight << " кило! " << endl;
		cout << "Охотников я не боюсь, ведь я умею прятаться." << endl;
		cout << "Посмотри на мои прекрасные глаза, они имеют ярко выраженнный " << color_eye << " оттенок, тебе нравится?" << endl;
		cout << "Ой, а ты видел мои миленькие крылышки, которые хранят в себе " << color_wings << " оттенок?" << endl;
		cout << "Тут так красиво, жаль, что я не знаю, где живу." << endl;
		cout << "Пора прощаться, навещай меня ещё, пожалуйста!" << endl;
		cout << endl;
	}
};
class Cherneti : public MamaCryak {
	bool hide;
	int height;
	string tail_form;

public:
	Cherneti() : hide(1), height(15 + (rand() % 31)), tail_form(tails[rand() % 10]) {};
	virtual ~Cherneti() {};
	virtual int is_fly() {
		return 0;
	}
	virtual int is_swim() {
		return 0;
	}
	virtual int is_hide() {
		return 1;
	}
	virtual int is_chill() {
		return 0;
	}
	virtual int is_migration() {
		return 0;
	}
	virtual int is_know() {
		return 0;
	}
	virtual  void get_info() {
		cout << "Асаламалейкум, на связи утка Чернети по кличке " << name << "." << endl;
		cout << "Мой вес составляет непосредственно " << weight << " кило! " << endl;
		cout << "Меня пугают охотники, но я умею хорошо прятаться." << endl;
		cout << "Я очень высокая утка, оцени, целых " << height << " см." << endl;
		cout << "О, ещё у меня класный " << tail_form << " хвост." << endl;
		cout << "А где я живу я и не знаю, но тут нормально." << endl;
		cout << "Досвидвнья!" << endl;
		cout << endl;
	}
};
class Shilohvost : public MamaCryak {
	int razmah;
	int width;
public:
	Shilohvost() : razmah(50 + (rand() % 41)), width(15 + (rand() % 21)) {
		know_home = 1;
		fly = 1;
	};
	virtual ~Shilohvost() {};
	virtual int is_fly() {
		if ((this->fly == 1) || (this->fly == 2)) {
			return 1;
		}
		else {
			return 0;
		}
	}
	virtual int is_swim() {
		return 0;
	}
	virtual int is_hide() {
		return 0;
	}
	virtual int is_chill() {
		return 0;
	}
	virtual int is_migration() {
		return 0;
	}
	virtual int is_know() {
		return 1;
	}
	virtual  void get_info() {
		cout << "Приветики, я  " << name << ", вида Шелохвость." << endl;
		cout << "Что то я поправилась, вешу аж " << weight << " кило! " << endl;
		if (fly == 1) {
			cout << "Хорошо что я умею летать" << endl;
		}
		else  if (fly == 2) {
			cout << "Однажды охотники поймали меня, но так как я умею летать, я смогла бежать." << endl;
		}
		else {
			cout << "Охотники дважды ловили меня, после чего подрезали мне крылья, теперь я не умею летьать.";
		}
		cout << "Господи, и в ширину я уже " << width << " см." << endl;
		cout << "Зато размах крыльев " << razmah << " см." << endl;
		cout << "Хорошо что хоть живу на " << home << endl;
		cout << "Мне пора!" << endl;
		cout << endl;
	}
};
class ZheltokluviyChirok : public MamaCryak {
	bool chill;
	int razmah;
	int age;

public:
	ZheltokluviyChirok() : chill(1), razmah(50 + (rand() % 41)), age(8 + (rand() % 8)) {};
	virtual ~ZheltokluviyChirok() {};
	virtual int is_fly() {
		return 0;
	}
	virtual int is_swim() {
		return 0;
	}
	virtual int is_hide() {
		return 0;
	}
	virtual int is_chill() {
		return 1;
	}
	virtual int is_migration() {
		return 0;
	}
	virtual int is_know() {
		return 0;
	}
	virtual  void get_info() {
		cout << "Я уточка вида Желтоклювый Чирок, а звать меня " << name << "." << endl;
		cout << "Вешу я " << weight << " кило. " << endl;
		cout << "Умею очень хорошо бездельничать." << endl;
		cout << "Размах моих крыльев составляет " << razmah << " см." << endl;
		cout << "А лет мне ой как много, уже целых " << age << "." << endl;
		cout << "А где я живу, я не знаю, может быть в матрице?" << endl;
		cout << "Мне пора, дела!" << endl;
		cout << endl;
	}
};
class KapskiyChirok : public MamaCryak {
	int kluv_size;
	string bludo;

public:
	KapskiyChirok() : kluv_size(7 + (rand() % 14)), bludo(bludos[rand() % 10]) {
		migration = 1;
	};
	virtual ~KapskiyChirok() {};
	virtual int is_fly() {
		return 0;
	}
	virtual int is_swim() {
		return 0;
	}
	virtual int is_hide() {
		return 0;
	}
	virtual int is_chill() {
		return 0;
	}
	virtual int is_migration() {
		return migration;
	}
	virtual int is_know() {
		return 0;
	}
	virtual  void get_info() {
		cout << "Я Капский Чирок по имени " << name << "." << endl;
		cout << "Мой вес " << weight << " кило. " << endl;
		cout << "Я люблю путешествовать, потому иногда мигрирую" << endl;
		cout << "Размер моего клюва " << kluv_size << " см." << endl;
		cout << "А мое любиимое блюдо это " << bludo << "." << endl;
		cout << "Но вот где я живу я не знаю." << endl;
		cout << "Ладно, прощай!" << endl;
		cout << endl;
	}
};
class HohlatayaYtka : public MamaCryak {
	int health;
	string color_eye;

public:
	HohlatayaYtka() : health(rand() % 101), color_eye(colors[rand() % 12]) {
		know_home = 1;
		fly = 1;
	};
	virtual ~HohlatayaYtka() {};
	virtual int is_fly() {
		if ((this->fly == 1) || (this->fly == 2)) {
			return 1;
		}
		else {
			return 0;
		}
	}
	virtual int is_swim() {
		return 0;
	}
	virtual int is_hide() {
		return 0;
	}
	virtual int is_chill() {
		return 0;
	}
	virtual int is_migration() {
		return 0;
	}
	virtual int is_know() {
		return 1;
	}
	virtual  void get_info() {
		cout << "Утка вида Хохлатая утка по имени " << name << " - это про меня." << endl;
		cout << "Я вешу около " << weight << " кило. " << endl;
		if (fly == 1) {
			cout << "Я умею летать" << endl;
		}
		else  if (fly == 2) {
			cout << "Однажды меня поймали, но я бежала благодаря тому, что умею летать." << endl;
		}
		else {
			cout << "Охотники, поймав меня 2 раза подрезади мне крылья, я не умею летать.";
		}
		cout << "Здоровье моё цело на " << health << " %." << endl;
		cout << "Мало кто знает, но у  моих глаз ярко выражен " << color_eye << " цвет." << endl;
		cout << "Живу я на " << home << endl;
		cout << "Прости, но меня ждут, пора бежать!" << endl;
		cout << endl;
	}
};
class Krohali_beta : public MamaCryak {
	bool chill;
	string tail_color;
	int health;

public:
	Krohali_beta() : chill(1), tail_color(colors[rand() % 12]), health(rand() % 101) {};
	virtual ~Krohali_beta() {};
	virtual int is_fly() {
		return 0;
	}
	virtual int is_swim() {
		return 0;
	}
	virtual int is_hide() {
		return 0;
	}
	virtual int is_chill() {
		return 1;
	}
	virtual int is_migration() {
		return 0;
	}
	virtual int is_know() {
		return 0;
	}
	virtual  void get_info() {
		cout << "Я кточка Крохали бета, звать " << name << "." << endl;
		cout << "Сколько вешу не скажу, а ладно скажу - " << weight << " кило. " << endl;
		cout << "Я отлично могу, умею, практикую бездельничать " << endl;
		cout << "Цвет моего хвостика " << tail_color << "." << endl;
		cout << "А если моё здоровье составляет " << health << " %, это хорошо?" << endl;
		cout << "А где я?(Не знает где живёт)" << endl;
		cout << "Мне пора бездельничать, уходи." << endl;
		cout << endl;
	}
};
class KapskiyChirok_beta : public MamaCryak {
	bool chill;
	int resistance;
	string wing_form;

public:
	KapskiyChirok_beta() : chill(1), resistance(rand() % 101), wing_form(wings[rand() % 5]) {};
	virtual ~KapskiyChirok_beta() {};
	virtual int is_fly() {
		return 0;
	}
	virtual int is_swim() {
		return 0;
	}
	virtual int is_hide() {
		return 0;
	}
	virtual int is_chill() {
		return 1;
	}
	virtual int is_migration() {
		return 0;
	}
	virtual int is_know() {
		return 0;
	}
	virtual  void get_info() {
		cout << "Я типо Капский Чирок бета, а звать меня " << name << "." << endl;
		cout << "Вешу немного, всего " << weight << " кило. " << endl;
		cout << "Умею бездельничкать - это мой конёк." << endl;
		cout << "Моя выносливость составляет " << resistance << " %." << endl;
		cout << "А крилья мои " << wing_form << "." << endl;
		cout << "Где я живу не знаю, но тут не так уж и плохо." << endl;
		cout << "Ой, а время то уже, я побежала!" << endl;
		cout << endl;
	}
};

//создания класса озер(т.к. ферма работает так же как и озеро, то этот же конструктор будем использовать для создания фермы
class Ozero {
	MamaCryak* head;
	string name_ozero;
	int size_list;
	int count_swim;
	int count_fly;
	int count_hide;
	int count_chill;
	int count_migration;
	int count_is_know;
public:
	Ozero(string name_ozero) :size_list(0), head(NULL), count_swim(0), count_fly(0), count_hide(0), count_chill(0), count_migration(0) { this->name_ozero = name_ozero; }
	~Ozero() {
		MamaCryak* tmp = NULL;
		if (head != NULL) {
			while (head->next != 0) {
				tmp = head;
				head = head->next;
				delete tmp;
				tmp = NULL;
			}
			delete head;
		}
	}
	void add_duck(MamaCryak* node) {
		MamaCryak* tmp = NULL;
		if (head == NULL) {
			head = node;
			head->next = NULL;
			size_list++;
			count_swim += (node->is_swim());
			count_fly += (node->is_fly());
			count_hide += (node->is_hide());
			count_chill += (node->is_chill());
			count_migration += (node->is_migration());
			count_is_know += (node->is_know());
		}
		else {
			tmp = head;
			while ((tmp) && (tmp->next)) {
				tmp = tmp->next;
			}
			if ((tmp != NULL) && (tmp->next == NULL)) {
				tmp->next = node;
				size_list++;
				count_swim += (node->is_swim());
				count_fly += (node->is_fly());
				count_hide += (node->is_hide());
				count_chill += (node->is_chill());
				count_migration += (node->is_migration());
				count_is_know += (node->is_know());
			}
		}
		if (node->know_home == 1) {
			node->home = name_ozero;
		}
	}
	int get_size() {
		return size_list;
	}
	void get_information() {
		cout << "В общей сложности проживает " << size_list << " уток" << endl;
		cout << "Из них: " << endl;
		cout << count_swim << " умеет(ют) плавать," << endl;
		cout << count_fly << " умеет(ют) летать," << endl;
		cout << count_hide << " умеет(ют) прятаться," << endl;
		cout << count_chill << " умеет(ют) бездельничать," << endl;
		cout << count_migration << " умеет(ют) мигрировать," << endl;
		cout << count_is_know << " знает(ют) где живет(ут)" << endl;
	}
	MamaCryak* delete_duck(int i) {
		i--;
		MamaCryak* prev, * tmp;
		tmp = head;
		if (i == 0) {
			head = head->next;
			tmp->next = NULL;
			size_list--;
			count_swim -= (tmp->is_swim());
			count_fly -= (tmp->is_fly());
			count_hide -= (tmp->is_hide());
			count_chill -= (tmp->is_chill());
			count_migration -= (tmp->is_migration());
			count_is_know -= (tmp->is_know());
			return tmp;
		}
		while (i != 1) {
			tmp = tmp->next;
			i--;
		}
		prev = tmp;
		tmp = tmp->next;
		prev->next = tmp->next;
		tmp->next = NULL;
		size_list--;
		count_swim -= (tmp->is_swim());
		count_fly -= (tmp->is_fly());
		count_hide -= (tmp->is_hide());
		count_chill -= (tmp->is_chill());
		count_migration -= (tmp->is_migration());
		count_is_know -= (tmp->is_know());
		return tmp;

	};
	MamaCryak* choose_duck(int i) {
		i--;
		MamaCryak* tmp;
		tmp = head;
		if (i == 0) {
			return tmp;
		}
		while (i != 0) {
			tmp = tmp->next;
			i--;
		}
		return tmp;

	};
};

class Hunter {
	int max_frags;
	int min_frags;
	string farm;
	string name;
public:
	Hunter(int max_frags, int min_frags, string farm, string name) : max_frags(0), min_frags(0), farm("~"), name("~") {
		this->max_frags = max_frags;
		this->min_frags = min_frags;
		this->farm = farm;
		this->name = name;
	};
	~Hunter() {};
	int Hunt(Ozero* ozero, Ozero* farm) {
		MamaCryak* b;
		int kills, dead = 0;
		int a, m, l;
		a = ozero->get_size();
		if (a == 0) {
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
			cout << "Все утки на этом озере пойманы!" << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
			return dead;
		}
		m = max_frags - min_frags;
		l = 1 + (rand() % a);
		kills = min_frags + (rand() % (m));
		cout << "Охотник " << name << " планирует словить " << kills << " уток(ку)(ки)" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
		for (int i = 0; i < kills; i++) {
			if (ozero->get_size() == 0) {
				cout << "Все утки на этом озере пойманы!" << endl;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
				return dead;
			}
			l = (1 + rand() % a);
			b = ozero->choose_duck(l);
			cout << name << " пытается поймать " << b->name << endl;
			if ((rand() % 4 != 0) && (b->is_hide() == 1)) {
				cout << b->name << " удалось спрятаться от " << name << endl;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
			}
			else {
				b = ozero->delete_duck(l);
				cout << b->name << " отправляется жить на ферму, благодаря " << name << endl;
				farm->add_duck(b);
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
				dead++;
			}
			a = ozero->get_size();
		}
		return dead;
	}
};

void migration(Ozero* a, Ozero* b, Ozero* c) {
	MamaCryak* duck;
	for (int i = 1; i <= a->get_size(); i++) {
		duck = a->choose_duck(i);
		if ((duck)&&(duck->is_migration() == 1)) {
			cout << " Уточка по имени " << duck->is_name() << " подумывает насчёт миграции" << endl;
			if (rand() % 3 == 0) {
				cout << "Нет, сегодня плохой день для миграции (" << duck->is_name() << " остается)" << endl;
				duck->migration_end();
			}
			else if (rand() % 3 == 1) {
				duck = a->delete_duck(i);
				b->add_duck(duck);
				cout << "Да, сегодня мигрирую на какое-нибудь озеро (" << duck->is_name() << " мигрирует на Кратерное озеро)" << endl;
				duck->migration_end();
				i--;
			}
			else {
				c->add_duck(duck);
				duck = a->delete_duck(i);
				cout << "Да, сегодня мигрирую на какое-нибудь озеро (" << duck->is_name() << " мигрирует на озеро Мьоса)" << endl;
				duck->migration_end();
				i--;
			}
		}
	}
	for (int i = 1; i <= b->get_size(); i++) {
		duck = b->choose_duck(i);
		if ((duck)&&(duck->is_migration() == 1)) {
			cout << " Уточка по имени " << duck->is_name() << " подумывает насчёт миграции" << endl;
			if (rand() % 3 == 0) {
				duck = b->delete_duck(i);
				a->add_duck(duck);
				cout << "Да, сегодня мигрирую на какое-нибудь озеро (" << duck->is_name() << " мигрирует на озеро Кива)" << endl;
				duck->migration_end();
				i--;
			}
			else if (rand() % 3 == 1) {
				cout << "Нет, сегодня плохой день для миграции (" << duck->is_name() << " остается)" << endl;
				duck->migration_end();
			}
			else {
				c->add_duck(duck);
				duck = b->delete_duck(i);
				cout << "Да, сегодня мигрирую на какое-нибудь озеро (" << duck->is_name() << " мигрирует на озеро Мьоса)" << endl;
				duck->migration_end();
				i--;
			}
		}
	}
	for (int i = 1; i <= c->get_size(); i++) {
		duck = c->choose_duck(i);
		if ((duck)&&(duck->is_migration() == 1)) {
			cout << " Уточка по имени " << duck->is_name() << " подумывает насчёт миграции" << endl;
			if (rand() % 3 == 0) {
				duck = c->delete_duck(i);
				a->add_duck(duck);
				cout << "Да, сегодня мигрирую на какое-нибудь озеро (" << duck->is_name() << " мигрирует на озеро Кива)" << endl;
				i--;
			}
			else if (rand() % 3 == 1) {
				duck = c->delete_duck(i);
				b->add_duck(duck);
				cout << "Да, сегодня мигрирую на какое-нибудь озеро (" << duck->is_name() << " мигрирует на Кратерное озеро)" << endl;
				i--;
			}
			else {
				cout << "Нет, сегодня плохой день для миграции (" << duck->is_name() << " остается)" << endl;
			}
			duck->migration_end();
		}
	}
	for (int i = 1; i <= a->get_size(); i++) {
		duck = a->choose_duck(i);
		if (duck->is_migration() == 2) {
			duck->migration_again();
		}
	}
	for (int i = 1; i <= b->get_size(); i++) {
		duck = b->choose_duck(i);
		if (duck->is_migration() == 2) {
			duck->migration_again();
		}
	}
	for (int i = 1; i <= c->get_size(); i++) {
		duck = c->choose_duck(i);
		if (duck->is_migration() == 2) {
			duck->migration_again();
		}
	}
}
void pobeg(Ozero* a, Ozero* b, Ozero* c, Ozero* farm) {
	MamaCryak* duck;
	int a1 = 0, b1 = 0;
	if (farm->get_size() == 0) {
		cout << " На ферме пока нет уток!" << endl;
	}
	else {
		cout << " Ну что, попробует ли сегодня кто то бежать?!" << endl;
		for (int i = 1; i <= farm->get_size(); i++) {
			duck = farm->choose_duck(i);
			if ((duck)&&((duck->is_fly() == 1) || (duck->is_fly() == 2)) && (duck->is_know() == 1)) {
				a1++;
				if (duck->is_fly() == 2) {
					cout << " Утке по имени " << duck->is_name() << " подрезают крылья, теперь точно не сбежит" << endl;
					duck->off_fly();
				}
				else {
					cout << " Уточка по имени " << duck->is_name() << " подумывает насчёт побега" << endl;
					if (rand() % 2 == 0) {
						cout << duck->is_name() << " не удалось сбежать" << endl;
					}
					else {
						b1++;
						duck->pre_off_fly();
						duck = farm->delete_duck(i);
						cout << "Сегодня " << duck->is_name() << " удалось бежать, но куда же она попадёт?" << endl;
						i--;
						if (rand() % 3 == 0) {
							a->add_duck(duck);
							cout << "Теперь у " << duck->is_name() << " начинается новая жизнь на озере Киву " << endl;
						}
						else if (rand() % 3 == 1) {
							b->add_duck(duck);
							cout << "Теперь у " << duck->is_name() << " начинается новая жизнь на Кратерном озере " << endl;
						}
						else {
							c->add_duck(duck);
							cout << "Теперь у " << duck->is_name() << " начинается новая жизнь на озере Мьоса " << endl;
						}
					}
				}
			}
		}
		cout << "Из " << a1 << " уток смогли сбежать только " << b1 << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	Hunter Hunter1(6, 1, "COBUMOT", "Джозеф"), Hunter2(6, 3, "COBUMOT", "Баласаньян");
	MamaCryak* a;
	int day = 0, get = 1;
	Ozero kivu("Киву"), kraternoe_ozero("Кратерное озеро"), mjosa("Мьоса"), COBUMOT("COBUMOT");
	int a1 = 26 + rand() % 11, b1 = 26 + rand() % 11, k = 92;
	k = k - a1 - b1;
	int m, catched1, catched2;
	for (int j = 0; j < a1; j++) {
		m = rand() % 3;
		if (m == 0) {
			kivu.add_duck(new Shirokonozhka);
		}
		else if (m == 1) {
			kivu.add_duck(new Krohali);
		}
		else {
			kivu.add_duck(new Cherneti);
		}
	}
	for (int j = 0; j < b1; j++) {
		m = rand() % 3;
		if (m == 0) {
			kraternoe_ozero.add_duck(new Shilohvost);
		}
		else if (m == 1) {
			kraternoe_ozero.add_duck(new ZheltokluviyChirok);
		}
		else {
			kraternoe_ozero.add_duck(new KapskiyChirok);
		}
	}
	for (int j = 0; j < k; j++) {
		m = rand() % 3;
		if (m == 0) {
			mjosa.add_duck(new HohlatayaYtka);
		}
		else if (m == 1) {
			mjosa.add_duck(new Krohali_beta);
		}
		else {
			mjosa.add_duck(new KapskiyChirok_beta);
		}
	}
	nachalo();
	for (; day <= 300; day++) {
		while (get != 0) {
			menu(day);
			cin >> get;
			switch (get) {
			case (1):
				system("cls");
				cout << "Какая(ое) именно озеро/ферма вас интересует?" << endl;
				cout << " 1 - озеро Киву " << endl;
				cout << " 2 - Кратерное озеро " << endl;
				cout << " 3 - озеро Мьоса " << endl;
				cout << " 4 - ферма COBUMOT " << endl;
				cin >> get;
				switch (get) {
				case (1):
					system("cls");
					if (kivu.get_size() != 0) {
						cout << "На озере Киву проживают утки в количетве " << kivu.get_size() << ". Какую хотите опросить?" << endl;
						do
						{
							cout << "Пожалуйста, для того, чтобы обратиться к утке, введиите конктретное значение в промежутке от 1 до " << kivu.get_size() << " включительно" << endl;
							cin >> get;
						} while (get > kivu.get_size() || get < 1);
						cout << endl;
						a = kivu.choose_duck(get);
						a->get_info();
						cout << endl;
					}
					else {
						cout << "На озере Киву, к сожалению, не осталось уток" << endl;
					}
					cout << " 1 - Вернуться в главное меню" << endl;
					cin >> get;
					switch (get) {
					case(1):
						system("cls");
						break;
					}
					break;
				case (2):
					system("cls");
					if (kraternoe_ozero.get_size() != 0) {
						cout << "На Кратерном озере проживают утки в количетве " << kraternoe_ozero.get_size() << ". Какую хотите опросить?" << endl;
						do
						{
							cout << "Пожалуйста, для того, чтобы обратиться к утке, введиите конктретное значение в промежутке от 1 до " << kraternoe_ozero.get_size() << " включительно" << endl;
							cin >> get;
						} while (get > kraternoe_ozero.get_size() || get < 1);
						cout << endl;
						a = kraternoe_ozero.choose_duck(get);
						a->get_info();
						cout << endl;
					}
					else {
						cout << "На Кратерном озере, к сожалению, не осталось уток" << endl;
					}
					cout << " 1 - Вернуться в главное меню" << endl;
					cin >> get;
					switch (get) {
					case(1):
						system("cls");
						break;
					}
					break;
				case (3):
					system("cls");
					if (mjosa.get_size() != 0) {
						cout << "На озере Мьоса проживают утки в количетве " << mjosa.get_size() << ". Какую хотите опросить?" << endl;
						do
						{
							cout << "Пожалуйста, для того, чтобы обратиться к утке, введиите конктретное значение в промежутке от 1 до " << mjosa.get_size() << " включительно" << endl;
							cin >> get;
						} while (get > mjosa.get_size() || get < 1);
						cout << endl;
						a = mjosa.choose_duck(get);
						a->get_info();
						cout << endl;
					}
					else {
						cout << "На озере Мьоса, к сожалению, не осталось уток" << endl;
					}
					cout << " 1 - Вернуться в главное меню" << endl;
					cin >> get;
					switch (get) {
					case(1):
						system("cls");
						break;
					}
					break;
				case (4):
					system("cls");
					if (COBUMOT.get_size() != 0) {
						cout << "На ферме COBUMOT проживают утки в количетве " << COBUMOT.get_size() << ". Какую хотите опросить?" << endl;
						do
						{
							cout << "Пожалуйста, для того, чтобы обратиться к утке, введиите конктретное значение в промежутке от 1 до " << COBUMOT.get_size() << " включительно" << endl;
							cin >> get;
						} while (get > COBUMOT.get_size() || get < 1);
						cout << endl;
						a = COBUMOT.choose_duck(get);
						a->get_info();
						cout << endl;
					}
					else {
						cout << "На ферме COBUMOT, к сожалению, пока нет уток" << endl;
					}
					cout << " 1 - Вернуться в главное меню" << endl;
					cin >> get;
					switch (get) {
					case(1):
						system("cls");
						break;
					}
				}
				break;
			case (2):
				system("cls");
				cout << "Какая(ое) именно озеро/ферма вас интересует?" << endl;
				cout << " 1 - озеро Киву " << endl;
				cout << " 2 - Кратерное озеро " << endl;
				cout << " 3 - озеро Мьоса " << endl;
				cout << " 4 - ферма COBUMOT " << endl;
				cin >> get;
				switch (get) {
				case(1):
					system("cls");
					cout << "Информация по озеру Киву:" << endl;
					kivu.get_information();
					cout << " 1 - Вернуться в главное меню" << endl;
					cin >> get;
					switch (get) {
					case(1):
						system("cls");
						break;
					}
					break;
				case(2):
					system("cls");
					cout << "Информация по Кратерному озеру:" << endl;
					kraternoe_ozero.get_information();
					cout << " 1 - Вернуться в главное меню" << endl;
					cin >> get;
					switch (get) {
					case(1):
						system("cls");
						break;
					}
					break;
				case(3):
					system("cls");
					cout << "Информация по озеру Мьоса:" << endl;
					mjosa.get_information();
					cout << " 1 - Вернуться в главное меню" << endl;
					cin >> get;
					switch (get) {
					case(1):
						system("cls");
						break;
					}
					break;
				case(4):
					system("cls");
					cout << "Информация по ферме CUBMOUT:" << endl;
					COBUMOT.get_information();
					cout << " 1 - Вернуться в главное меню" << endl;
					cin >> get;
					switch (get) {
					case(1):
						system("cls");
						break;
					}
					break;
				}
				break;
			}
		}
		get = 1;
		system("cls");
		if ((rand() % 3 == 0) && (kivu.get_size() != 0)) {
			cout << "Охотa будет на озере Киву " << endl;
			catched1 = Hunter1.Hunt(&kivu, &COBUMOT);
			catched2 = Hunter2.Hunt(&kivu, &COBUMOT);
			cout << "За " << day + 1 << " день охоты было поймано " << catched1 + catched2 << " уток!" << endl;
			cout << "День охоты окончен!" << endl;
		}
		else if ((rand() % 2 == 0) && (kraternoe_ozero.get_size() != 0)) {
			cout << "Охотa будет на Кратерном озере " << endl;
			catched1 = Hunter1.Hunt(&kraternoe_ozero, &COBUMOT);
			catched2 = Hunter2.Hunt(&kraternoe_ozero, &COBUMOT);
			cout << "За " << day + 1 << " день охоты было поймано " << catched1 + catched2 << " уток!" << endl;
			cout << "День охоты окончен!" << endl;
		}
		else if ((mjosa.get_size() != 0)) {
			cout << "Охотa будет на озере Мьоса " << endl;
			catched1 = Hunter1.Hunt(&mjosa, &COBUMOT);
			catched2 = Hunter2.Hunt(&mjosa, &COBUMOT);
			cout << "За " << day + 1 << " день охоты было поймано " << catched1 + catched2 << " уток!" << endl;
			cout << "День охоты окончен!" << endl;
		}
		if ((kivu.get_size() == 0) && (kraternoe_ozero.get_size() == 0) && (mjosa.get_size() == 0)) {
			system("cls");
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "| Охотники победили, все утки пойманы! |" << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			return 0;
		}
		migration(&kivu, &kraternoe_ozero, &mjosa);
		pobeg(&kivu, &kraternoe_ozero, &mjosa, &COBUMOT);
	}
	return 0;
}