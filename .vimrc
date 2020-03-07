" add number to each line 
set number

" set the color style to koehler, change to other color by command :colo <Tab>
colo koehler

filetype plugin indent on
" show existing tab with 4 spaces width
set tabstop=4
" when indenting with '>', use 4 spaces width
set shiftwidth=4
" On pressing tab, insert 4 spaces
set expandtab

" to show the whitespaces in vim
 :set listchars=eol:¬,tab:>·,trail:~,extends:>,precedes:<,space:␣
" :set listchars=eol:¬,tab:>·,trail:~,extends:>,precedes:<,space:.
:set list

" set colors for all whitespaces to dark gray
:hi Whitespace ctermfg=DarkGray
:match Whitespace /\s/

