
#ifndef CONVERTOR_HPP
#define CONVERTOR_HPP

# include <string>

class Convertor
{
   private :
		Convertor();
		Convertor(const Convertor&);
		Convertor& operator=(const Convertor&);

    public :
		~Convertor();

		static void convert(const std::string& literal);
};

#endif