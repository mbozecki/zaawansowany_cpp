class Singleton {
private:
	Singleton();
	static Singleton* classinstance;
	static int callsnum;
public:
	~Singleton();
	
	static Singleton* instance();
	void calls();
};

