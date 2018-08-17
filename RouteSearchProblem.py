if __name__=="__main__":
    input_string = input()
    length = len(input_string) - 1
    
    map_data = [[0 for i in range(length)] for j in range(length)]
    
    for count1 in range(0, length):
        if count1 > 0:
            input_string = input()
        for count2 in range(0, length):
            map_data[count1][count2] = int(input_string[count2])
            
    work = [[0 for i in range(length)] for j in range(length)]
    route_x = [[0 for i in range(length)] for j in range(length)]
    route_y = [[0 for i in range(length)] for j in range(length)]
    
    work[0][0] = map_data[0][0]
    
    for x in range(1, length):
        work[0][x] = work[0][x - 1] + map_data[0][x]
    
    for y in range(1, length):
        work[y][0] = work[y - 1][0] + map_data[y][0]
    
    for x in range(1, length):
        for y in range(1, length):
            if work[y][x - 1] < work[y - 1][x]:
                work[y][x] = work[y][x - 1] + map_data[y][x]
            else:
                work[y][x] = work[y - 1][x] + map_data[y][x]
    
    x = length - 1
    y = length - 1
    
    for i in range(length * 2 - 2, 0):
        route_x[i] = x
        route_y[i] = y
        if x == 0 and y == 0:
            break
        if y == 0:
            x -= 1
        elif x == 0:
            y -= 1
        elif work[y][x - 1] > work[y - 1][x]:
            x -= 1
        else:
            y -= 1
    
    print(work[length - 1][length - 1])
