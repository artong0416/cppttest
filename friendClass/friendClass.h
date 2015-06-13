#ifndef FRIENDCLASS_H
#define FRIENDCLASS_H
class Date{
	public:
		Date(int year, int month, int day){
			this->year=year;//this指针
			this->month=month;
			this->day=day; 
		}
		
		friend class AccessDate;//声明友元类
		 
	private:
		int year;
		int month;
		int day;
};
#endif
