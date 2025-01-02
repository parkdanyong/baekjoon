'''
    title: 샤워실 바닥 깔기(Large)
    tag: Divide and Conquer
'''



import sys


def layTiles(field, f_row, f_col, tileNum = 1) :
    '''
         field frame coordinate is left top position
        :parameter field: field
        :parameter f_row: frame row coordinate
        :parameter f_col: frame col coordinate
        :parameter tileNum: tile number



    '''


    if len(field[0]) != 2 :
        layTiles(field//2, f_row, f_col, tileNum=tileNum)
        layTiles(field//2, f_row, f_col+2, tileNum=tileNum+1)
        layTiles(field//2, f_row+2, f_col, tileNum=tileNum+2)
        layTiles(field//2, f_row+2, f_col+2, tileNum=tileNum+3)


    





size = 2**int(sys.stdin.readline()) # get size
hole = [int(i) for i in sys.stdin.readline().split()] # get hole's position
field = [[0] * size for i in range(size)] # init field











