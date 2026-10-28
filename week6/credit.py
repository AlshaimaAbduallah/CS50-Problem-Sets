from cs50 import get_string

def is_valid_luhn(card):
    total_sum = 0
    reverse_card = card[::-1]

    for i in range(len(reverse_card)):
        digit = int(reverse_card[i])

        if i % 2 == 1:
            doubled = digit * 2
            if doubled > 9:
                total_sum += (doubled // 10) + (doubled % 10)
            else:
                total_sum += doubled
        else:
            total_sum += digit

    return total_sum % 10 == 0

def main():
    card = get_string("Number: ").strip()

    if not card.isdigit():
        print("INVALID")
        return

    if not is_valid_luhn(card):
        print("INVALID")
        return

    length = len(card)
    prefix_two = card[:2]
    prefix_one = card[0]

    if length == 15 and (prefix_two == "34" or prefix_two == "37"):
        print("AMEX")
    elif length == 16 and (prefix_two >= "51" and prefix_two <= "55"):
        print("MASTERCARD")
    elif (length == 13 or length == 16) and prefix_one == "4":
        print("VISA")
    else:
        print("INVALID")

if __name__ == "__main__":
    main()
