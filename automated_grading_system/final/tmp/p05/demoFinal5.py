import sys


def verify_maze(f_maze, stu_ans):
    maps = []
    gold_starts = []
    stu_start = []
    stu_routes = []
    maps, gold_starts = find_golden(f_maze)
    stu_routes, stu_start = find_student(stu_ans)
    for i in range(len(stu_start)):
        if stu_start[i] != gold_starts[i]:
            print(f' Wrong Start Node ({stu_start[i][0]}, {stu_start[i][1]})')
            return

    for i in range(len(maps)):
        first = True
        for p in range(len(stu_routes[i])):
            row = int(stu_routes[i][p][0]) - 1
            col = int(stu_routes[i][p][1]) - 1

            # print(row, col)
            if maps[i][row][col] == '0':
                if first:
                    first = False
                    continue
                if abs(int(stu_routes[i][p][0]) - int(stu_routes[i][p-1][0])) + abs(int(stu_routes[i][p][1]) - int(stu_routes[i][p-1][1])) > 1:
                    print(
                        f'Wrong Route For Start Point: ({stu_start[i][0]}, {stu_start[i][1]})')
                    return
                    # for i in range(len(maps)):
                    #     print(stu_routes[i])
                    #     print(stu_start)

        row = int(stu_routes[i][p][0]) - 1
        col = int(stu_routes[i][p][1]) - 1
        if row != 0 and row != len(maps[i]) - 1 and col != 0 and col != len(maps[i][0]) - 1 and len(stu_routes[i]) > 1:
            print(
                f'Wrong End For Start Point: ({row}, {col})')
            return


def find_golden(f_maze):
    maps = []
    starts = []
    ans = []
    with open(f_maze, 'r') as f:
        lines = f.readlines()
        i = 0
        while i < len(lines):
            if lines[i].strip() == '.':
                map = []
                i += 1
                while lines[i][0] != '[':
                    if len(lines[i].strip()) == 0:
                        i += 1
                        continue
                    map = map + [list(lines[i].strip())]
                    i += 1
                maps = maps + [map]
                start = lines[i].strip()[1:-2].replace('(', '').split('),')
                start = [points.strip().replace(' ', '').split(',')
                         for points in start]
                starts = starts + [start]
                i += 1

            else:
                i += 1

        for id in range(len(maps)):
            for s in range(len(starts[id])):
                # print(starts[id][s])
                row = int(starts[id][s][0]) - 1
                col = int(starts[id][s][1]) - 1
                if maps[id][row][col] == '0':
                    ans = ans + [starts[id][s]]
                    break
    return maps, ans


def find_student(stu_ans):
    routes = []
    starts = []

    with open(stu_ans, 'r') as f:
        lines = f.readlines()
        i = 0
        while i < len(lines):
            if lines[i].strip() == '.':
                route = []
                i += 1
                start = lines[i].strip()[1:-1].replace(' ', '').split(',')
                starts = starts + [[start[0], start[1]]]
                i += 1
                route = lines[i].strip()[
                    2:-2].split('), (')
                route = [point.strip().replace(' ', '').split(',')
                         for point in route]
                routes = routes + [route]
                i += 1
            else:
                i += 1

    return routes, starts


verify_maze(sys.argv[1], sys.argv[2])

