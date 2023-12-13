 ++++[>++++[>+++<-]<-] # Init '0' in cell(2)
    ,>,>               # Read two numbers
    [<-<->>-]          # Decrement by '0'
    <<                 # Go to cell(0)
    [                  # Multiplication loop
        >              # Go to cell(1)
        [>+>+<<-]      # Move to cells(2) and (3)
        >>             # Go to cell(3)
        [<<+>>-]       # Move to cell(1)
        <<<-           # Decrement cell(0)
    ]
    >[-]<              # Reset cell(1) to 0
    ++++[>++++[>+++<-]<-] # Add '0' to cell(2)
    >>.                   # Print result
