if __FILE__ == $0
    input_string = gets.chomp
    length = input_string.length - 1
    
    map_data = Array.new
    
    (0..length).each do |count1|
        if count1 > 0 then
            input_string = gets.chomp
        end
        map_data << input_string.split("").map(&:to_i)
    end
    
    work = Array.new(length + 1).map{Array.new(length + 1, 0)}
    route_x = Array.new(length + 1)
    route_y = Array.new(length + 1)
    
    work[0][0] = map_data[0][0]
    
    (1..length).each do |x|
        work[x][0] = work[x - 1][0] + map_data[0][x]
    end
    
    (1..length).each do |y|
        work[0][y] = work[0][y - 1] + map_data[y][0]
    end
    
    (1..length).each do |x|
        (1..length).each do |y|
            if work[y][x - 1] > work[y - 1][x] then
                work[y][x] = work[y - 1][x] + map_data[x][y]
            else
                work[y][x] = work[y][x - 1] + map_data[x][y]
            end
        end
    end
    
    x = length - 1
    y = length - 1
    buf = length * 2 - 2
    
    (buf..0).each do |i|
        route_x[i] = x
        route_y[i] = y
        if x == 0 and y == 0 then
            break
        end
        
        if y == 0 then
            x -= 1
        elsif x == 0 then
            y -= 1
        elsif work[y][x - 1] > work[y - 1][x] then
            x -= 1
        else
            y -= 1
        end
    end
    
    puts work[length][length]
end
