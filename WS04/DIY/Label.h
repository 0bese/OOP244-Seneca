#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H

namespace sdds {
	class Label{
		char m_frameArg[9] {};
		char* m_content;
	public:
		Label();
		Label(const char* frameArg);
		Label(const char* frameArg, const char* content);
		~Label();

		std::istream&readLabel();
		std::ostream&printLabel()const;

		Label& text(const char* content);
	};
}

#endif