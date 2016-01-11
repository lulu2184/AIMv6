diskutil unmount /Volumes/KERNEL
diskutil unmount /Volumes/BOARD
diskutil unmount /Volumes/P0
diskutil unmount /Volumes/P1
diskutil unmount /Volumes/P2
diskutil unmount /Volumes/P3
sudo dd if=user/kern.elf of=/dev/disk2s2
sync
diskutil unmount /Volumes/KERN
diskutil unmount /Volumes/BOARD
diskutil unmount /Volumes/P0
diskutil unmount /Volumes/P1
diskutil unmount /Volumes/P2
diskutil unmount /Volumes/P3

