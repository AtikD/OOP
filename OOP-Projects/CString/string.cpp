#include "string.hpp"

/// <summary>
/// ����������� �� ���������.
/// </summary>
CString::CString() {
    size_ = 0;
    capacity_ = STEP_CAPACITY;
    data_ = new char[capacity_];
    data_[0] = '\0';
}

/// <summary>
/// ����������� �����������.
/// </summary>
/// <param name="str"> - ���������� ������</param>
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
/// ����������� ������
/// </summary>
/// <param name="c_str"> - ������.</param>
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
/// ����������� ������ � ������������ ������������ ��������
/// </summary>
/// <param name="c_str"> - ������.</param>
/// <param name="n"> - ���-�� ��������.</param>
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
/// �����������, ��������� ����� ������� n ���
/// </summary>
/// <param name="n"> - ���-�� ����� �������.</param>
/// <param name="c"> - ������.</param>
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
/// ����������� ������� "��������" �����
/// </summary>
/// <param name="str"> - ������</param>
/// <param name="pos"> - ������� ������</param>
/// <param name="len"> - ���-�� ��������</param>
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
/// ����������.
/// </summary>
CString::~CString() {
    delete[] data_;
    data_ = nullptr;
}

/// <summary>
/// ����� ������ � �������
/// </summary>
void CString::print() const noexcept
{
    std::cout << data_ << std::endl;
}

/// <summary>
/// �������� ������ �� �������.
/// </summary>
/// <returns>
/// true - ���� ������ �����,
/// false - �����.
/// </returns>
bool CString::empty() const noexcept {
    return size_ == 0;
}

/// <summary>
/// ������ ��� ������� ������.
/// </summary>
/// <returns>������ (�����) ������</returns>
size_t CString::size() const noexcept {
    return size_;
}

/// <summary>
/// ������ ��� ������� ���������
/// </summary>
/// <returns>������ (�����) ������ </returns>
size_t CString::capacity() const noexcept
{
    return capacity_;
}

/// <summary>
/// ������ ��� ���������
/// </summary>
/// <returns>��������� � ���� char*</returns>
const char* CString::data() const
{
    return data_;
}

/// <summary>
/// ������� ��������� (�������������������).
/// </summary>
/// <param name="str"> - ������ ��� ���������</param>
/// <returns>
/// 1 - ���� �������� ������ ������,
/// -1 - ���� �������� ������ ������,
/// 0 - ���� ������ ���������.
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
/// ������� ���������
/// </summary>
void CString::clear() noexcept
{
    size_ = 0;
    capacity_ = STEP_CAPACITY;
    data_ = new char[capacity_];
    data_[0] = '\0';
}


/// <summary>
/// ������� ������� � ����� ������.
/// </summary>
/// <param name="c"> - ������ ��� �������</param>
/*void CString::push_back(char c) {
    if (this->full()) {
        this->reserve(capacity_);
    }

    data_[size_] = c;
    data_[++size_] = '\0';
}
*/
/// <summary>
/// �������� ������� �� ����� ������.
/// <exception cref="std::logic_error">����������, ���� �������� ������ �����.</exception>
/// </summary>
void CString::pop_back() {
    if (this->empty()) {
        throw std::logic_error("Error in function \
                  \"void pop_back()\": source CString is empty");
    }
    data_[--size_] = '\0';
}
/// <summary>
/// �������� �������
/// </summary>
/// <param name="pos"> - ������� ������</param>
/// <param name="len> - ���������� �������� ��� ��������</param>
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

// ���� ������ ����������
/// <summary>
/// ������� ������ ����� �������� ������� � ��������.
/// </summary>
/// <param name="pos"> - ������� ��� ������� � �������� ������.</param>
/// <param name="str"> - ������ ��� �������</param>
/// <returns>��������� �������� ������</returns>
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
/// ����� ������� ���������� � �������� ������ � ����� �� �������� �������� ������.
/// </summary>
/// <param name="str"> - ����� �������� ��� ������</param>
/// <param name="pos"> - �������, � ������� ������� �������� �����</param>
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
