
def remove_after_kth(items, k=1):
    sets= set(items)
    unq_v = list(sets)
    total=[None]*len(items)
    if (k>0):
        for i in unq_v:
            c0unt=0
            for j in range(len(items)):
                if (i == items[j]):
                    c0unt+=1 
                    if (c0unt<=k):
                        total[j]= items[j]
    total= list(filter(lambda a:a != None,total))
    
    return total

def is_ascending(items):
  result = False
  if len(items) == 1:
    return True
  else:
    for i in range (len(items)-1):
      if items[i] < items[i+1]:
        result = True
      else:
        return False
  return result

def riffle(items, out = True):
  i = 0
  x = 0
  list1 = items[0:int(len(items)/2)]
  list2 = items[int(len(items)/2):]
  list3 = items.copy()
  if out == True:
    while i < (len(items)):
      list3[i] = list1[x]
      list3[i+1] = list2[x]
      x += 1
      i = 2 + i
  else:
    while i < (len(items)):
      list3[i] = list2[x]
      list3[i+1] = list1[x]
      x += 1
      i = 2 + i
  return list3

def only_odd_digits(n):
  result = True
  count = 0
  if n % 2 == 0:
    return False
  while n != 0:
    count = n % 10
    if count % 2 == 0:
      return False
    else:
      n = n // 10
  return result

def is_cyclops(n):
  result = True
  count = 0
  n = str(n)
  x = int(((len(n)-1)) / 2)
  if len(n) % 2 == 0:
    return False
  else:
    for i in range (len(n)-1):
      if (n[i]) == "0":
        count += 1
      if count == 2:
        return False
    if (n[x]) != "0":
      result = False
  return result

def taxi_zum_zum(moves):
  y = 0
  x = 0
  rotation = 90 # usingcartesian coordinate system
  for i in range (len(moves)):
    if rotation == 360:
      rotation = 0
    elif rotation == -360:
      rotation = 0
    if moves[i] == 'R':
      rotation -= 90
    elif moves[i] =='L':
      rotation += 90
    else:
      if rotation == 90 or rotation == (-270):
        y += 1
      elif rotation == 180 or rotation == -180:
        x -= 1
      elif rotation == 270 or rotation == (-90):
        y -= 1
      else:
        x += 1
  return "(" + str(x) + ", " + str(y) + ")"

def count_dominators(items):
  total = 0
  result = False
  i = 0
  length = len(items)- 1
  if len(items) == 0:
    return total
  elif len(items) == 1:
    return total + 1
  else:
    while i <= (length):
      x = i + 1
      if i == length:
        return total + 1
      else:
        while x <= length:
          if items[i] > items[x]:
            result = True
          else:
            result = False
            x = length + 1
          x += 1
      if result == True:
        total += 1
      i += 1

def give_change(amount, coins):
  i = 0
  result = []
  while amount != 0:
    if (amount - coins[i]) < 0:
      i += 1
    else:
      amount = amount - coins[i]
      result.append(int(coins[i]))
  return result

def domino_cycle(tiles):
  x = 0
  if len(tiles) == 1:
    return tiles[0][0] == tiles [0][1]
  elif len(tiles) == 0:
    return True
  else:
    while x <= (len(tiles)-2):
      if tiles[x][1] == tiles[x+1][0]:
        x += 1
      else:
        return False
    if tiles[0][0] == tiles[-1][1]:
      return True
    else:
      return False

def extract_increasing(digits):
  result = []
  result.append(int(digits[0]))
  i = 0
  x = 1
  y = 2
  testing = 0
  while y <= (len(digits)):
      testing = int(digits[x:y])
      if result[i] >= testing:
          y += 1
      else:
          result.append(testing)
          x = y
          y = 1 + y
          i += 1
  return (result)

def create_zigzag(rows, cols, start = 1):
  result = []
  x = 0
  i = start
  while x <= (rows-1):
    list_1 = []
    while i <= (cols + start - 1):
      list_1.append(x*cols + i)
      i += 1
    if x % 2 != 0:
      list_1.reverse()
    result.append(list_1)
    list_1 = []
    i = start
    x += 1
  return result

def pyramid_blocks(n, m, h):
  total = 0
  for i in range(h):
    total += n*m
    n += 1
    m += 1
  return total

def pancake_scramble(text):
  x = 2
  result = text[0:2]
  result = result[::-1]
  while x <= (len(text)-1):
    result += text[x]
    result = result[::-1]
    x += 1
  return (result)

def safe_squares_rooks(n, rooks):
  x_coord = []
  y_coord = []
  x = 0
  y = 0
  i = 0
  while i <= (len(rooks)-1):
      x = rooks[i][0]
      y = rooks[i][1]
      if x not in x_coord:
        x_coord.append(x)
      if y not in y_coord:
        y_coord.append(y)
      i += 1
  if (n-len(x_coord))*(n-len(y_coord)) < 0:
      return (0)
  else: 
      return ((n-len(x_coord))*(n-len(y_coord)))

def knight_jump(knight, start, end):
  jump = list(map(lambda i,j: abs(i-j), start, end))
  jump.sort(reverse = True)
  if list(knight) == list(jump):
    return True
  else:
    return False

def winning_card(cards, trump = None):
  rank = ["two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "jack", "queen", "king", "ace"]
  highest_card = 0
  h_card_value = 0
  i = 0
  winning_suit = ""
  if trump == None or (cards[0][1] != trump and cards[1][1] != trump and cards[2][1] != trump and cards[3][1] != trump):
    winning_suit = cards[0][1]
  else:
    winning_suit = trump
  while i <= 3:
    if winning_suit == cards[i][1]:
       if h_card_value <= rank.index(cards[i][0]):
         h_card_value = rank.index(cards[i][0])
         highest_card = i
    i += 1
  return cards[highest_card]

def josephus(n,k): 
  list_men = []
  men_died = []
  i = 1
  man_selector = 0
  counter = 1
  listjumper = 0
  while i <= n:
      list_men.append(i)
      i+= 1
  while (len(list_men)!= 1):
      if k <= len(list_men):
          listjumper = k
      elif k % len(list_men) == 0:
          listjumper = len(list_men)
      else:
          listjumper = k % len(list_men)
      while counter < listjumper:
          if man_selector == len(list_men):
              man_selector = 0
          man_selector += 1
          counter +=1
      if man_selector == len(list_men):
            man_selector = 0
      men_died.append(list_men[man_selector])
      list_men.pop(man_selector)
      man_selector -= 1
      counter = 0
  men_died.append(list_men[0])
  return men_died

def tukeys_ninthers(items):
  list1 = []
  n = 0
  result = False
  medianfinder = 0
  while result == False:
    if (len(items)) == 1:
      return items[0]
    medianfinder = tuple(items[n:n+3])
    if (medianfinder[0] <= medianfinder[1] <= medianfinder[2]) or (medianfinder[2] <= medianfinder[1] <= medianfinder[0]):
      list1.append(medianfinder[1])
    elif (medianfinder[2] <= medianfinder[0] <= medianfinder[1]) or (medianfinder[1] <= medianfinder[0] <= medianfinder[2]):
      list1.append(medianfinder[0])
    else:
      list1.append(medianfinder[2])
    for i in range(3):
      items.pop(0)
    if len(items) == 0:
      items = list1

def crag_score(dice):
  sum = dice[0] + dice[1] + dice[2]
  maximum_count = 0
  maximum = 0
  max_value = 0
  min_value = 0
  minimum_count = 0
  minimum = 0
  dice_sorted = sorted(dice)
  if (((dice[1] == dice[2]) or (dice[1] == dice[0]) or (dice[2] == dice[0])) and sum == 13):
    return 50
  elif sum == 13:
    return 26
  elif dice[0] == dice[1] and dice[0] == dice[2]:
    return 25
  elif dice_sorted == [1,2,3]:
    return 20
  elif dice_sorted == [4,5,6]:
    return 20
  elif dice_sorted == [1,3,5]:
    return 20
  elif dice_sorted == [2,4,6]:
    return 20
  else:
    maximum = max(dice)
    maximum_count = dice.count(maximum)
    max_value = maximum_count*maximum
    minimum = min(dice)
    minimum_count = dice.count(minimum)
    min_value = minimum_count*minimum
    if max_value >= min_value:
      return max_value
    else:
      return min_value

def frog_collision_time(frog1, frog2):
  sx1, sy1, dx1, dy1 = frog1
  sx2, sy2, dx2, dy2 = frog2
  if dx1 == dx2 and sx1 != sx2:
    return None
  elif dy1 == dy2 and sy1 != sy2:
    return None
  elif dx1 == dx2 and sx1 == sx2:
    if (((sy1-sy2)/(dy2-dy1)) < 0) or ((sy1-sy2)%(dy2-dy1) != 0):
      return None
    elif int((sy1-sy2)/(dy2-dy1)) == 0 :
      return None
    else:
      return int((sy1-sy2)/(dy2-dy1))
  elif dy1 == dy2 and sy1 == sy2:
    if ((sx1-sx2)/(dx2-dx1) < 0) or ((sx1-sx2)%(dx2-dx1) != 0):
      return None
    elif int((sx1-sx2)/(dx2-dx1)) == 0 :
      return None
    else:
      return int((sx1-sx2)/(dx2-dx1))
  else:
    t1 = ((sx1-sx2)/(dx2-dx1))
    t2 = ((sy1-sy2)/(dy2-dy1))
    if ((sy1-sy2)%(dy2-dy1) != 0) or ((sx1-sx2)%(dx2-dx1) != 0):
      return None
    if t1 < 0 or t2 < 0:
      return None
    elif int(t1) == 0 or int(t2) == 0:
      return None
    if t1 == t2:
      return int(t1)
    else:
      return None

def count_growlers(animals):
  growl = 0
  cats = 0
  dogs = 0
  i = 0
  start = True
  while i < (len(animals)):
    if start == True:
        end_begining = i - 1 # <-
        begining_end = i + 1 # ->
        start = False
    if (animals[i] == "cat") or (animals[i] == "dog"): # <-
      if end_begining == -1:
        if dogs > cats:
          growl += 1
          dogs, cats = 0,0
          start = True
          i += 1
        else:
          dogs, cats = 0,0
          start = True
          i += 1
      else:
        if (animals[end_begining] == "cat") or (animals[end_begining] == "tac"):
          cats += 1
        elif (animals[end_begining] == "dog") or  (animals[end_begining] == "god"):
          dogs += 1
        end_begining -= 1
    else:
      if begining_end == (len(animals)):
        if dogs > cats:
          growl += 1
          dogs, cats = 0,0
          start = True
          i += 1
        else:
          dogs, cats = 0,0
          start = True
          i += 1
      else:
        if (animals[begining_end] == "cat") or (animals[begining_end] == "tac"):
          cats += 1
        elif (animals[begining_end] == "dog") or  (animals[begining_end] == "god"):
          dogs += 1
        begining_end += 1
  return growl

def sum_of_two_squares(n):
  a = int(n**0.5)
  marker = a
  b = n - a*a
  c = int(b**0.5)
  while a > marker/2:
    if a*a + c*c == n:
      if c == 0:
        return None
      else:
        return (a,c)
    else:
      a-= 1
      b = n - a*a
      c = int(b**0.5)
  return None

def bulgarian_solitaire(piles,k):
  result = False
  remover = 0
  counter = 0
  turns = 0
  if len(piles) == k:
    for x in range(k):
      if x+1 in piles:
        counter += 1
    if counter == k:
      return turns
    else:
      counter = 0
  while result == False:
    if 0 in piles:
      remover = piles.index(0)
      piles.pop(remover)
    else:
      for i in range(len(piles)):
        piles[i] = piles[i] - 1
      piles.append(len(piles))
      turns += 1
      if len(piles) == k:
          for x in range(k):
            if x+1 in piles:
              counter += 1
          if counter == k:
            return turns
          else:
            counter = 0

def seven_zero(n):
  def sevengenerator(n):
    value = 7
    while (value % n) != 0:
      value = value * 10 +7
    return value

  def sevenzero(n):
      result = False
      d = 1
      value = ""
      while result == False:
          value = ""
          k = 1
          while k <= d:
              value = "7"*k + "0"*(d-k)
              if (int(value) % n) == 0:
                  return int(value)
              else:
                  k+= 1
          d += 1
  if (n % 2 == 0) or (n % 5 == 0):
    return sevenzero(n)
  else:
    return sevengenerator(n)

def count_consecutive_summers(n):
    if n <= 2:
      return 1
    count = 0
    if (n % 2) == 1:
      count += 1
    if (n // 2) % 2 == 1:
      # this n / 2 number is now odd
      m = n // 2
    else:
      # the number is even when n / 2
      m = (n // 2) -1
    while m > 1:
      if (n / m) == int(n/m):
        count += 1
      m -= 2
    return count + 1

def words_with_given_shape(words,shape):
  pot_words = []
  count = 0
  for line in words:
    count = 0
    if (len(line) == len(shape)+1):
      for i in range (len(shape)):          
        if (shape[i] == -1) and (ord(line[i]) > ord(line[i+1])):
            count += 1
        elif (shape[i] == 1) and (ord(line[i]) < ord(line[i+1])):
          count += 1
        elif (shape[i] == 0) and (ord(line[i]) == ord(line[i+1])):
          count += 1
        if count == len(shape):
          pot_words.append(line)
          count = 0
  return pot_words

def three_summers(items,goal):
  for i in range(len(items)-1):
    for x in range(i+1,len(items) -1):
      if (goal - items[i] - items[x]) in items[x+1:]:
        return True
  return False

def is_left_handed(pips):
  right_hand = [(1,3,2),(1,2,4),(1,4,5),(1,5,3),(6,2,3),(6,3,5),(6,5,4),(6,4,2)]
  x = pips
  for i in range(3):
    x1, x3, x2 = x
    if x in right_hand:
      return False
    else:
      x = (x3, x2, x1)
  return True

def group_and_skip(n,out, ins):
  result = []
  while n // out != 0:
    result.append(n%out)
    n = ((n // out) * ins)
  result.append(n)
  return result

def is_zigzag(n): 
  x = str(n)
  if len(x) == 1:
    return True
  elif ((int(x[0])) > (int(x[1]))):
    marker = 0
  elif ((int(x[0])) < (int(x[1]))):
    marker = 1
  for i in range(1,len(x)-1):
    if marker == 1 and ((int(x[i])) > (int(x[i+1]))):
      marker = 0
    elif marker == 0 and ((int(x[i])) < (int(x[i+1]))):
      marker = 1
    else:
      return False
  return True

def reverse_reversed(items):
  x = items
  result = []
  for i in range((len(x)-1),-1,-1):
    if type(x[i]) == list:
      result.append(reverse_reversed(x[i]))
    else:
      result.append(x[i])
  return result

def words_with_letters(words, letters):
    n = 0
    pot_words = []
    for line in words:
        n = 0
        count = 0
        if (len(line) >= len(letters)):
            for i in range (len(letters)):
                if letters[i] in line[n:]:
                    n = n + line[n:].index(letters[i])+1
                    count += 1
            if len(letters) == count:
                pot_words.append(line)
    return pot_words

def count_carries(a,b):
    count = 0
    n = 0
    while (a > 0) or (b > 0):
        c = a%10
        d = b%10
        if c+d+n > 9:
            n = 1
            count += 1
        else:
            n = 0
        a = a//10
        b = b//10
    return count

def expand_intervals(intervals):
  numbers = []
  x = intervals.split(",")
  for i in range(len(x)):
      if "-" in x[i]:
          y = x[i].split("-")
          for k in range(int(y[0]),int(y[1])+1):
              numbers.append(k)
      else:
          numbers.append(int(x[i]))
  return (numbers)

def reverse_vowels(text):
    vowels = "aeiouAEIOU"
    vowel_ord = ""
    result = ""
    for i in range(len(text)):
        if text[i] in vowels:
            vowel_ord = vowel_ord + text[i]
    count = len(vowel_ord)-1
    for x in range(len(text)):
        if text[x] in vowels:
            if (vowels.index(text[x])) > 4:
                result =result + vowel_ord[count].capitalize()
                count =count - 1
            else:
                result = result + vowel_ord[count].casefold()
                count =count - 1
        else:
            result = result + text[x]
    return result

def reverse_ascending_sublists(items):
  result = []
  n = 0
  for i in range(len(items)):
      if (i == len(items)-1):
          for r in range(i,n-1,-1):
              result.append(items[r])
      elif items[i] >= items[i+1]:
          for r in range(i,n-1,-1):
              result.append(items[r])
          n = i + 1
  return result

def duplicate_digit_bonus(n):
    points = 0
    count = 1
    length = str(n)
    for i in range(len(length)-1):
        if length[i] == length[i+1]:
            count += 1
            if (i+1 == len(length)-1) and count >= 2:
                points = points + 2*10**(count-2)
        else:
            if count > 1:
                points = points + 10**(count-2)
                count = 1
    return points

def collapse_intervals(items):
    redce = ""
    first = items[0]
    if len(items) == 1:
      return str(first)
    for i in range(len(items)-1):
        if i+1 ==len(items)-1:
            if items[i+1] == items[i]+1:
                redce = redce + str(first) + "-" + str(items[i+1])
                return redce
            else:
                if first == items[i]:
                  redce = redce + str(first) + ","
                else:
                  redce = redce + str(first) + "-" + str(items[i])+ ","
                redce = redce + str(items[i+1])
                return redce
        elif items[i+1] != items[i]+1:
            if first == items[i]:
                redce = redce + str(first) + ","
                first = items[i+1]
            else:
                redce = redce + str(first) + "-" + str(items[i]) + ","
                first = items[i+1]

def can_balance(items):
    left = 0
    right = 0
    if len(items) == 1:
        return 0
    for i in range(1,len(items)-1):
        left = 0
        right = 0
        for x in range(len(items[0:i])):
            left = left + items[i-x-1]*(x+1)
        for y in range(len(items[i+1:])):
            right = right + items[y+i+1]*(y+1)
        if left == right:
            return i
    return -1

def nearest_smaller(items):
    result = []
    left = 0
    right = 0
    ind = 0
    while ind < len(items):
        if (items[ind] > items[left]) and (items[ind] > items[right]):
            if items[left] < items[right]:
                result.append(items[left])
            else:
                result.append(items[right])
            left = ind+1
            right = ind +1
            ind += 1
        elif items[ind] > items[left]:
            result.append(items[left])
            left = ind+1
            right = ind +1
            ind += 1
        elif items[ind] > items[right]:
            result.append(items[right])
            left = ind+1
            right = ind +1
            ind += 1
        elif left == 0 and right == len(items)-1:
            result.append(items[ind])
            left = ind+1
            right = ind +1
            ind += 1
        else:
            if left != 0:
                left -= 1
            if right != len(items) -1:
                right += 1
    return result


def ztalloc(shape):
    n = 1
    for i in range((len(shape)-1),-1,-1):
        if n <= 0:
            return None
        elif shape[i] == "d":
            n = (n*2)
        else:
            if ((n-1)%3) != 0:
                return None
            else:
                n = ((n-1)//3)
                if n%2==0:
                  return None
    return (n)

def eliminate_neighbours(items):
  largest = max(items)
  minimum = 0
  count = 0
  while largest in items:
    minimum = min(items)
    min_index = items.index(minimum)
    if min_index == 0:
      if len(items) == 1:
          items.pop()
      else:
          items.pop(0)
          items.pop(0)
      count += 1
    elif min_index == (len(items)-1):
      items.pop()
      items.pop()
      count += 1
    else:
      if items[min_index-1] > items[min_index+1]:
        items.pop(min_index-1)
        items.pop(min_index-1)
      else:
        items.pop(min_index)
        items.pop(min_index)
      count += 1
  return count


def squares_intersect(s1, s2):
  x1, y1, r1 = s1
  x2, y2, r2 = s2
  if x1 <= x2:
    if y1 < y2:
      return ((x1+r1) >= x2) and ((y1+r1) >= y2)
    else:
      return ((x1+r1) >= x2) and ((y2+r2) >= y1)
  if x2 <= x1:
    if y2 < y1:
      return ((x2+r2) >= x1) and ((y2+r2) >= y1)
    else:
      return ((x2+r2) >= x1) and ((y1+r1) >= y2)

def count_and_say(digits):
  number = ""
  count = 1
  idnum = digits[0]
  if len(digits) == 0:
    return ""
  elif len(digits) == 1:
    return "1"+ digits
  else:
    for i in range(1,len(digits)):
      if i == len(digits)-1:
        if idnum == digits[i]:
          return (number+str(count+1)+idnum)
        else:
          number = number + str(count) + idnum
          return number + "1" + digits[i]
      elif idnum == digits[i]:
        count += 1
      else:
        number = number + str(count) + idnum
        idnum = digits[i]
        count = 1

def postfix_evaluate(items):
  result = []
  a = 0
  b = 0
  for i in range(len(items)):
    if items[i] == '+':
      a = result[-2]
      b = result[-1]
      result.pop()
      result.pop()
      result.append(a+b)
    elif items[i] == '*':
      a = result[-2]
      b = result[-1]
      result.pop()
      result.pop()
      result.append(a*b)
    elif items[i] == '-':
      a = result[-2]
      b = result[-1]
      result.pop()
      result.pop()
      result.append(a-b)
    elif items[i] == '/':
      a = result[-2]
      b = result[-1]
      result.pop()
      result.pop()
      if b == 0:
        result.append(0)
      else:
        result.append(a//b)
    else:
      result.append(items[i])
  return result[0]

def remove_after_kth(items, k =1):
  result = []
  word_checker = []
  count  = []
  if k == 0:
    return []
  else:
    for i in range(len(items)):
      if items[i] in word_checker:
        if k != count[word_checker.index(items[i])]:
          result.append(items[i])
          count[word_checker.index(items[i])] += 1
      else:
        result.append(items[i])
        word_checker.append(items[i])
        count.append(1)
  return result


def count_word_dominators(words):
  checker = 0
  count = 0
  word_checker = 0
  for i in range(len(words)):
    checker = 0
    word_checker = 0
    for x in range(i+1, len(words)):
      if len(words[i]) > len(words[x]):
        checker += 1
      elif len(words[i]) == len(words[x]):
        for y in range(len(words[i])):
          if words[i][y] > words[x][y]:
            word_checker += 1
          else:
            word_checker -= 1
        if word_checker > 0:
          checker += 1
          word_checker = 0
    if checker == len(words[i+1:]):
      count += 1
  return count

def oware_move(board, house):
  n = board[house]
  board[house] = 0
  marker = house+1
  while n > 0:
    board[marker] += 1
    n -= 1
    if n == 0:
      break
    if marker + 1== house:
      marker += 2
    elif marker+ 1 == len(board):
      if house == 0:
        marker = 1
      else:
        marker = 0
    else:
      marker += 1
  while marker > (len(board)//2)-1:
    if board[marker] == 2 or board[marker] == 3:
      board[marker] = 0
      marker -= 1
    else:
      break
  return board

def fractran(n,prog, giveup = 100):
  result = [n]
  count = 0
  x = True
  marker = 0
  if len(prog) == 0:
    return [n]
  while x == True:
    a, b = prog[marker]
    if a*result[-1]%b == 0:
      result.append(a*result[-1]//b)
      count += 1
      marker = 0
      if count == giveup:
        return result
    else:
      if marker + 1 == len(prog):
        return result
      else:
        marker += 1

def frequency_sort(items):
  items.sort()
  number = []
  number_id = []
  result = []
  for i in range(len(items)):
    if items[i] not in number:
      number.append(items[i])
      number_id.append((1,items[i]))
    else:
      z = (number.index(items[i]))
      valuea, valueb = number_id[z]
      number_id[z] = (valuea+1,valueb)
  number_id.sort(reverse = True)
  marker = 0
  toorganize = False
  organize = []
  for h in range(len(number_id)-1):
    a, b = number_id[h]
    c,d = number_id[h+1]
    if ((a == c) and toorganize == False):
      if h + 1 == len(number_id)-1:
        organize = number_id[h:]
        organize.sort(reverse = False)
        number_id[h:] = organize
      else:
        marker = h
        toorganize = True
    elif((a != c) and toorganize == True):
      organize = number_id[marker:h+1]
      organize.sort(reverse = False)
      number_id[marker:h+1] = organize
      toorganize = False
    elif ((a == c) and toorganize == True and h+1 == len(number)-1):
      organize = number_id[marker:]
      organize.sort(reverse = False)
      number_id[marker:] = organize
  for x in range(len(number)):
    l, k = number_id[x]
    for y in range(l):
        result.append(k)
  return result

          
def possible_words(words, pattern):
  letters = []
  marker = []
  result = []
  for i in range(len(pattern)):
    if pattern[i] != '*':
      if pattern[i] not in letters:
        letters.append(pattern[i])
        marker.append(i)
      else:
        marker.append(i)
  for line in words:
    if len(line) == len(pattern):
      count = 0
      for x in range(len(pattern)):
        if pattern[x] == line[x]:
          count += 1
        elif (pattern[x] == "*") and (line[x] in letters):
          count = -1
          break
      if count == len(marker):
        result.append(line)
  return result