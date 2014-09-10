import urllib.request

file = open('stats.mmt','w')

#For formating html
info_start = 0
info_end   = False

counter    = 0
list_start = False
line_out   = ''
temp_line  = ''

for url_line in urllib.request.urlopen('http://www.lolking.net/champions/'):

    #For formating html
    line = str(url_line)
    if (line.find('Aatrox') != -1): info_start = info_start + 1
    if (line.find('Percentages are based on weekly') != -1): info_end = True

    #Getting a word from html
    word        = ''
    bracket     = True      #Tactical bug!
    if (info_start>1) and (info_end == False):
        ####print(line)
        for i in range(0,len(line)-3): #was url_line
            if (line[i]=='<'): bracket=True
            if (bracket==False) and (line[i] != '\\'): word = word + line[i]
            if (line[i]=='>'): bracket=False
        ####file.write(word + '\n')
        ####print(word)

    word_list = word.split()
    if (len(word_list) != 0): list_start = True
    if (list_start == True):
        counter = counter + 1

        if (len(word_list)>0):
            temp_line = word_list[0]
            for i in range(1,len(word_list)):
                temp_line = temp_line + ' ' + word_list[i]
            line_out = line_out + '@' + temp_line

    if (counter==9):
        line_out = line_out + '\n'
        file.write(line_out)
        list_start = False
        line_out = ''
        counter = 0
file.close()
