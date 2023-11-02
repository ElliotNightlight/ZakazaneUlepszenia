#ifndef ZAKAZANA_HPP
#define ZAKAZANA_HPP


// Number types

#include <cstddef>
#include <cstdint>

typedef int8_t  Int8;
typedef int16_t Int16;
typedef int32_t Int32;
typedef int64_t Int64;

typedef uint8_t  UInt8;
typedef uint16_t UInt16;
typedef uint32_t UInt32;
typedef uint64_t UInt64;

constexpr Int8  Int8_MAX  = INT8_MAX;
constexpr Int8  Int8_MIN  = INT8_MIN;
constexpr Int16 Int16_MAX = INT16_MAX;
constexpr Int16 Int16_MIN = INT16_MIN;
constexpr Int32 Int32_MAX = INT32_MAX;
constexpr Int32 Int32_MIN = INT32_MIN;
constexpr Int64 Int64_MAX = INT64_MAX;
constexpr Int64 Int64_MIN = INT64_MIN;

constexpr UInt8  UInt8_MAX  = UINT8_MAX;
constexpr UInt16 UInt16_MAX = UINT16_MAX;
constexpr UInt32 UInt32_MAX = UINT32_MAX;
constexpr UInt64 UInt64_MAX = UINT64_MAX;

typedef ptrdiff_t IntSize;
typedef size_t    UIntSize;

typedef float       Float32;
typedef double      Float64;
typedef long double FloatExt;


// Iterating

class Range {
    IntSize m_Begin;
    IntSize m_End;
public:
    Range(IntSize count) : m_Begin(0), m_End(count) {}
    Range(IntSize begin, IntSize end) : m_Begin(begin), m_End(end) {}
    class iterator {
        IntSize m_Number;
    public:
        iterator(IntSize number) : m_Number(number) {}
        IntSize operator*() const { return m_Number; }
        iterator& operator++() { ++m_Number; return *this; }
        bool operator!=(const iterator& other) const { return m_Number != other.m_Number; }
    };
    iterator begin() const { return iterator(m_Begin); }
    iterator end() const { return iterator(m_End); }
};

class RangeReversed {
    IntSize m_Begin;
    IntSize m_End;
public:
    RangeReversed(IntSize count) : m_Begin(0), m_End(count) {}
    RangeReversed(IntSize begin, IntSize end) : m_Begin(begin), m_End(end) {}
    class iterator {
        IntSize m_Number;
    public:
        iterator(IntSize number) : m_Number(number) {}
        IntSize operator*() const { return m_Number; }
        iterator& operator++() { --m_Number; return *this; }
        bool operator!=(const iterator& other) const { return m_Number != other.m_Number; }
    };
    iterator begin() const { return iterator(m_End-1); }
    iterator end() const { return iterator(m_Begin-1); }
};


// Containers

template<typename T, IntSize L, IntSize R>
class Array {
    T m_Array[R-L];
public:
    Array() {
        ;
    }
    T& operator[](IntSize i) { return m_Array[i-L]; }
    class iterator {
        T* m_Ptr;
    public:
        iterator(T* ptr) : m_Ptr(ptr) {}
        T& operator*() const { return *m_Ptr; }
        iterator& operator++() { ++m_Ptr; return *this; }
        bool operator!=(const iterator& other) { return m_Ptr != other.m_Ptr; }
    };
    iterator begin() const { return iterator(m_Array); }
    iterator end() const { return iterator(m_Array + R-L); }
};

#endif

