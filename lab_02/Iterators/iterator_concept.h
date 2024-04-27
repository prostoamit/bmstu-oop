#ifndef ITERATOR_CONCEPT_H
#define ITERATOR_CONCEPT_H

template <typename I>
concept Iterator = requires()
{
    typename I::value_type;
    typename I::difference_type;
    typename I::pointer;
    typename I::reference;
};

#endif //ITERATOR_CONCEPT_H
