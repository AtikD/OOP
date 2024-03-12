#include "string.hpp"

/// <summary>
/// Конструктор по умолчанию.
/// </summary>
CString::CString() {
    size_ = 0;
    capacity_ = STEP_CAPACITY;
    data_ = new char[capacity_];
    data_[0] = '\0';
}

/// <summary>
/// Конструктор копирования.
/// </summary>
/// <param name="str"> - копируемая строка</param>
CString::CString(const CString& str) {
    size_ = str.size_;
    capacity_ = str.capacity_;
    data_ = new char[capacity_];
    for (size_t i = 0; i < size_; i++) {
        data_[i] = str.data_[i];
    }
    data_[size_] = '\0';
}

/// <summary>
/// Конструктор строки
/// </summary>
/// <param name="c_str"> - строка.</param>
CString::CString(const char* c_str) {
    size_ = 0;
    while (c_str[size_] != '\0') size_++;

    capacity_ = (size_ / STEP_CAPACITY) * STEP_CAPACITY + STEP_CAPACITY;
    data_ = new char[capacity_];
    for (size_t i = 0; i < size_; i++) {
        data_[i] = c_str[i];
    }
    data_[size_] = '\0';
}

/// <summary>
/// Конструктор строки с ограниченным колличеством символов
/// </summary>
/// <param name="c_str"> - строка.</param>
/// <param name="n"> - кол-во символов.</param>
CString::CString(const char* c_str, size_t n) {
    size_ = 0;
    while (c_str[size_] != '\0' && size_ < n) size_++;

    capacity_ = (size_ / STEP_CAPACITY) * STEP_CAPACITY + STEP_CAPACITY;
    data_ = new char[capacity_];
    for (size_t i = 0; i < size_; i++) {
        data_[i] = c_str[i];
    }
    data_[size_] = '\0';
}

/// <summary>
/// Конструктор, создающий копию символа n раз
/// </summary>
/// <param name="n"> - кол-во копий символа.</param>
/// <param name="c"> - символ.</param>
CString::CString(size_t n, char c)
{
    size_ = n;
    capacity_ = (size_ / STEP_CAPACITY) * STEP_CAPACITY + STEP_CAPACITY;
    data_ = new char[capacity_];
    for (size_t i = 0; i < size_; i++) {
        data_[i] = c;
    }
    data_[size_] = '\0';
}

/// <summary>
/// Конструктор который "обрезает" текст
/// </summary>
/// <param name="str"> - строка</param>
/// <param name="pos"> - позиция старта</param>
/// <param name="len"> - кол-во символов</param>
CString::CString(const CString& str, size_t pos, size_t len)
{
    if (pos + len > str.size_)
        throw CString("No enough size");
    size_ = len;

    capacity_ = (size_ / STEP_CAPACITY) * STEP_CAPACITY + STEP_CAPACITY;
    data_ = new char[capacity_];
    for (size_t i = 0; i < size_; i++) {
        data_[i] = str.data_[pos + i];
    }
    data_[size_] = '\0';
}

/// <summary>
/// Деструктор.
/// </summary>
CString::~CString() {
    delete[] data_;
    data_ = nullptr;
}

/// <summary>
/// Вывод строки в консоль
/// </summary>
void CString::print() const noexcept
{
    std::cout << data_ << std::endl;
}

/// <summary>
/// Проверка строки на пустоту.
/// </summary>
/// <returns>
/// true - если строка пуста,
/// false - иначе.
/// </returns>
bool CString::empty() const noexcept {
    return size_ == 0;
}

/// <summary>
/// Геттер для размера строки.
/// </summary>
/// <returns>размер (длина) строки</returns>
size_t CString::size() const noexcept {
    return size_;
}

/// <summary>
/// Геттер для размера хранилища
/// </summary>
/// <returns>размер (длина) строки </returns>
size_t CString::capacity() const noexcept
{
    return capacity_;
}

/// <summary>
/// Геттер для хранилища
/// </summary>
/// <returns>Хранилище в виде char*</returns>
const char* CString::data() const
{
    return data_;
}

/// <summary>
/// Функция сравнения (лексикографического).
/// </summary>
/// <param name="str"> - строка для сравнения</param>
/// <returns>
/// 1 - если исходная строка больше,
/// -1 - если исходная строка меньше,
/// 0 - если строки совпадают.
/// </returns>
int CString::compare(const CString& str) const noexcept {
    for (size_t i = 0; i < algorithms::min(size_, str.size_); i++) {
        if (this->data_[i] < str.data_[i]) {
            return 1;
        }
        else if (this->data_[i] > str.data_[i]) {
            return -1;
        }
    }
    if (this->size_ > str.size_) return 1;
    else if (this->size_ < str.size_) return -1;
    else return 0;
}

/// <summary>
/// Очищает хранилище
/// </summary>
void CString::clear() noexcept
{
    size_ = 0;
    capacity_ = STEP_CAPACITY;
    data_ = new char[capacity_];
    data_[0] = '\0';
}


/// <summary>
/// Вставка символа в конец строки.
/// </summary>
/// <param name="c"> - символ для вставки</param>
/*void CString::push_back(char c) {
    if (this->full()) {
        this->reserve(capacity_);
    }

    data_[size_] = c;
    data_[++size_] = '\0';
}
*/
/// <summary>
/// Удаление символа из конца строки.
/// <exception cref="std::logic_error">Исключение, если исходная строка пуста.</exception>
/// </summary>
void CString::pop_back() {
    if (this->empty()) {
        throw std::logic_error("Error in function \
                  \"void pop_back()\": source CString is empty");
    }
    data_[--size_] = '\0';
}
/// <summary>
/// Удаление участка
/// </summary>
/// <param name="pos"> - позиция старта</param>
/// <param name="len> - количество символов для удаления</param>
/*
CString& CString::erase(size_t pos, size_t len)
{
    while(data_[pos] != '\0' || len!=0)
    {
        data_[pos] = data_[pos + 1];
        size_--;
        len--;
    }

}
*/

// лишь пример реализации
/// <summary>
/// Вставка строки после заданной позиции в исходной.
/// </summary>
/// <param name="pos"> - позиция для вставки в исходной строке.</param>
/// <param name="str"> - строка для вставки</param>
/// <returns>изменённая исходная строка</returns>
/*
CString& CString::insert(size_t pos, const CString& str) {
    CString begin(*this, 0, pos);
    CString end(*this, pos, size_ - pos);
    begin.append(str);
    begin.append(end);
    this->swap(begin);
    return *this;
}
*/
/// <summary>
/// Поиск первого совпадения в исходной строке с одним из символов заданной строки.
/// </summary>
/// <param name="str"> - набор символов для поиска</param>
/// <param name="pos"> - позиция, с которой следует начинать поиск</param>
/// <returns></returns>
size_t CString::find_first_of(const CString& str, size_t pos) const {
    for (size_t i = pos; i < size_; i++) {
        for (size_t j = 0; j < str.size_; j++) {
            if (data_[i] == str.data_[j]) {
                return i;
            }
        }
    }
    return -1;
}
