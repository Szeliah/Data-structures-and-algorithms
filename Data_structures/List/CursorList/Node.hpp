#pragma once

template<typename T>
class Node {
    T value;
    int next;

    friend class CursorList;
};
 
