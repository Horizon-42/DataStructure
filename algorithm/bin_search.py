def search(items, item):
    s = 0
    f = len(items)
    cnt = 0
    while f-s >= 1:
        cnt = cnt+1
        i = (f+s)//2
        if items[i] == item:
            print('search %d times,' % cnt, end=' ')
            return i
        elif items[i] < item:
            s = i+1
        else:
            f = i-1
    print('search %d times,' % cnt, end=' ')
    return -1


if __name__ == '__main__':
    import random
    items = []
    for i in range(0, 1000):
        items.append(random.randint(-100, 100))

    for i in range(0, 100):
        item = random.randint(-100, 100)
        index = search(items, item)
        if index == -1:
            print('no match!')
        else:
            print('%d %d' % (index, items[index]))
