#ifndef FRIENDCLASS_H
#define FRIENDCLASS_H
class Date{
	public:
		Date(int year, int month, int day){
			this->year=year;//thisָ��
			this->month=month;
			this->day=day; 
		}
		
		friend class AccessDate;//������Ԫ��
		 
	private:
		int year;
		int month;
		int day;
};
#endif
