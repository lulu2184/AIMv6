diskutil unmount /Volumes/KERN
diskutil unmount /Volumes/BOARD
sudo dd if=kern/kern_test.elf of=/dev/disk2s2
sudo dd if=mbr.bin of=/dev/disk2 count=1 bs=446
sync
diskutil unmount /Volumes/KERN
diskutil unmount /Volumes/BOARD

